#include <iostream>

constexpr int MAX_NM = 1001, MAX_M = 100001;

int dp[MAX_M][MAX_NM];
int n, m , M;

void solve(){
    dp[0][0] = 1;
    for(int i = 1; i <= m; ++i){
        for(int j = 0; j <= n; ++j){
            if(j - i >= 0){
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return;
}

int main(){
    std::cin >> n >> m >> M;
    solve();
    std::cout << dp[m][n] << std::endl;
    return 0;
}
