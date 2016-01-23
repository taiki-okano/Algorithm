#include <iostream>
#include <cstring>

constexpr int MAX_N = 100;
constexpr int MAX_AMK = 100000;

int n, k;
int a[MAX_AMK], m[MAX_AMK]

int dp [MAX_AMK] = {-1};

void solve(){
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            if(dp[j] >= 0) dp[j] = m[i];
            else if(j < a[i] || dp[j - a[i]] <= 0) dp[j] = -1;
            else dp[j] = dp[j - a[i]] - 1;
        }
    }
    return;
}

int main(){
    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> a[i] >> m[i];
    std::cin >> k;
    solve();
    std::cout << dp[k];
    return 0;
}
