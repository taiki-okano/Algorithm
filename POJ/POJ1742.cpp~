#include <iostream>
#include <cstring>

constexpr int MAX_AM = 100001, MAX_C = 1001;

int n, m, a[MAX_AM], c[MAX_AM];

int dp[MAX_AM];

void solve(){
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= m; ++j){
            if(dp[j] >= 0) dp[j] = c[i];
            else if(j < a[i] || dp[j - a[i]] <= 0) dp[j] = -1;
            else dp[j] = dp[j - a[i]] - 1;
        }
    }
}

int main(){
    while(true){
        std::cin >> n >> m;
        if(n + m == 0) break;
        for(int i = 0; i < n; ++i) std::cin >> a[i];
        for(int i = 0; i < n; ++i) std::cin >> c[i];
        solve();
        int count = 0;
        for(int i = 1; i <= m; ++i){
            if(dp[i] != -1) ++count;
        }
        std::cout << count << std::endl;
    }
    return 0;
}
