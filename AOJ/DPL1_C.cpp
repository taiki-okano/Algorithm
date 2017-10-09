#include <cstdio>
#include <algorithm>

constexpr int MAX_N = 100, MAX_vw = 1000, MAX_W = 10000;

int N, W;
int v[MAX_N], w[MAX_W];
int dp[MAX_N + 1][MAX_W + 1];

void solve();

int main(){
    scanf("%d%d", &N, &W);
    for(int i = 0; i < N; ++i){
        scanf("%d%d", &v[i], &w[i]);
    }
    solve();
}

void solve(){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= W; ++j){
            if(j < w[i]){
                dp[i + 1][j] = dp[i][j];
            }
            else{
                dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[N][W]);
}
