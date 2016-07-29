#include <cstdio>
#include <algorithm>

constexpr int MAX_X = 4, MAX_Y = 50;

int main(){
    while(true){
        int X, Y, Z;
        int roulette[MAX_X], jump[MAX_Y]{}, get_money[MAX_Y]{};
        float dp[MAX_Y + 1][100 * MAX_Y + 1]{1};
        scanf("%d%d%d", &X, &Y, &Z);
        if(!X){
            break;
        }
        for(int i = 0; i < X; ++i){
            scanf("%d", &roulette[i]);
        }
        for(int i = 0; i < Z; ++i){
            int n, e, a;
            scanf("%d%d%d", &n, &e, &a);
            switch(e){
                case 1:
                    jump[n] = a;
                    break;
                case 2:
                    get_money[n] = a;
                    break;
                case 3:
                    get_money[n] = -a;
                    break;
            }
        }
        for(int i = 0; i < Y; ++i){
            for(int j = 0; j <= 100 * MAX_Y; ++j){
                if(dp[i][j] == 0){
                    continue;
                }
                for(int k = 0; k < X; ++k){
                    int ni, nj;
                    ni = std::min(i + roulette[k], Y);
                    nj = std::max(j + get_money[ni], 0);
                    ni = std::min(ni + jump[ni], Y);
                    dp[ni][nj] += dp[i][j] / X;
                }
            }
        }
        float ans = 0;
        for(int i = 0; i <= 100 * MAX_Y; ++i){
            ans += dp[Y][i] * i;
        }
        printf("%d\n", (int)ans);
    }
    return 0;
}
