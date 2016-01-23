#include <iostream>
#include <algorithm>

constexpr int MAX_N = 101, MAX_W = 10001, MAX_VW = 1001;

int n, max_w, w[MAX_N], v[MAX_N], dp[MAX_N][MAX_W];

void fill_dp(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= max_w; ++j){
            if(j < w[i]) dp[i + 1][j] = dp[i][j];
            else dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
        }
    }
    return;
}

void solve(){
    fill_dp();
    std::cout << dp[n][max_w] << std::endl;
    return;
}

int main(){
    std::cin >> n >> max_w;
    for(int i = 0; i < n; ++i)
        std::cin >> v[i] >> w[i];
    solve();
    
    return 0;
}
