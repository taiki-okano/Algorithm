#include <iostream>
#include <algorithm>

const int MAX_NM = 100;

int N, M;
double table[MAX_NM][MAX_NM];
double dp[MAX_NM][MAX_NM];

int main(){

    while(true){
        std::cin >> N >> M;
    
        if(N == 0 && M == 0)
            break;

        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j)
                std::cin >> table[i][j];
        }

        for(int i = 0; i < M; ++i){
            for(int j = 0; j < N; ++j){
                if(i == 0){
                    dp[i][j] = 1;
                }
                else{
                    int max = 0;
                    for(int k = 0; k < N; ++k){
                        max = std::max(max, table[k][j] * dp[i - 1][k]);
                    }

                    dp[i][j] = max;
                }
            }
        }
        
        int ans = 0;

        for(int i = 0; i < N; ++i)
            ans = std::max(dp[M - 1][i], ans);
        
        std::cout << ans << " "/* << std::endl*/;

    }
    return 0;
}
