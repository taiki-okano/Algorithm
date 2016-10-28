#include <cstdio>
#include <algorithm>

constexpr int MAX_NM = 100;

int main(){
    int N, M;
    float table[MAX_NM][MAX_NM]{}, dp[MAX_NM][MAX_NM]{};
    
    while(true){
        scanf("%d%d", &N, &M);
        if(N == 0 && M == 0){
            break;
        }
        
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                scanf("%f", &table[i][j]); // [prev][now]
            }
        }

        for(int i = 0; i < M; ++i){
            for(int j = 0; j < N; ++j){
                if(i == 0){
                    dp[i][j] = 1;
                    continue;
                }
                float max = 0;
                for(int k = 0; k < N; ++k){
                    max = std::max(max, dp[i - 1][k] * table[k][j]);
                }
                dp[i][j] = max;
            }
        }

        float ans = 0;

        for(int i = 0; i < N; ++i){
            ans = std::max(ans, dp[M - 1][i]);
        }
        printf("%.2f\n", float(int(ans * 100 + 0.5)) / 100);
    }

    return 0;
}
