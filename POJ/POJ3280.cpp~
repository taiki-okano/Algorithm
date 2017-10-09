#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

const int MAX_N = 26;
const int MAX_M = 2030;
const int MAX_COST = 10000;

int N, M;
int cost[MAX_N];
int dp[MAX_M][MAX_M];

int main(){
    std::string str;
    std::cin >> N >> M >> str;

    for(int i = 0; i < N; ++i){
        char c;
        int a, b;
        std::cin >> c >> a >> b;
        cost[c - 'a'] = std::min(a, b);
   }

    for(int i = 0; i < M; ++i){
        for(int j = 0; j < M; ++j)
            dp[i][j] = 0;
    }

    for(int len = 1; len < M; ++len){
        for(int i = 0, j = len; j < M; ++i, ++j){
            if(str[i] == str[j]){
                if(j - i == 1)
                    dp[i][j] = dp[i + 1][j + 1];
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }
            dp[i][j] = std::min(dp[i + 1][j] + cost[str[j] - 'a'], dp[i][j - 1] + cost[str[i] - 'a']);
        }
    }

    std::cout << dp[0][M - 1] << std::endl;

    return 0;
}
