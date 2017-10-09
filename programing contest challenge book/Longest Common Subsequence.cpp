#include <iostream>
#include <algorithm>
#include <string>

const int MAX_NM = 1000;

int n, m;
int dp[MAX_NM][MAX_NM];
std::string s, t;

int main(){
    std::cin >> n >> m >> n >> m;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(s[i] == t[j])
                dp[i + 1][j + 1] = std::max({dp[i][j] + 1, dp[i + 1][j], dp[i][j + 1]});
            else
                dp[i + 1][j + 1] = std::max({dp[i + 1][j], dp[i][j + 1]});
        }
    }

    std::cout << dp[n][m] << std::endl;

    return 0;
}
