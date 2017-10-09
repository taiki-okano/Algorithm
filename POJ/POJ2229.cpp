#include <iostream>
#include <cstring>

const int MAX_N = 1000001;

long dp[MAX_N];

int main(){
    int n;
    std::cin >> n;

    memset(dp, 0, sizeof(dp));
    
    dp[1] = 1;
    
    for(int i = 2; i <= MAX_N; ++i){
        if(i % 2 == 0)
            dp[i] += dp[i / 2];
            
        dp[i] += dp[i - 1];
        dp[i] %= 1000000000;
    }
    
    std::cout << dp[n] << std::endl;
    
    return 0;
}