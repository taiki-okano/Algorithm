#include <iostream>

constexpr int MAX_N = 1000000, MAX_M = 10000000;

long long dp[MAX_M];
long long tmp[MAX_M];
int n, m;

int main(){
    std::cin >> n >> m;
    dp[n - 1] = 1, dp[n] = 1;
    tmp[n - 1] = 1, tmp[n] = 1;
    for(int i = n + 1; i <= m; ++i){
        dp[i] = tmp[i - 1] - tmp[i - n - 1];
        tmp[i] = dp[i] + tmp[i - 1];
        dp[i] %= 10007;
    }
    std::cout << dp[m] % 10007 << std::endl;
    return 0;
}
