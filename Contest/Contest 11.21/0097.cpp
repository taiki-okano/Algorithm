#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

const int MAX_N = 11;
const int MAX_NUMS = 101;
const int MAX_S = 1001;

long long dp[MAX_NUMS][MAX_S];

void solve(){
    dp[0][0] = 1;
    for(int i = 0; i < MAX_NUMS; ++i)
        for(int j = 9; j >= 0; --j)
            for(int k = 0; i + k < MAX_S; ++k)
                dp[j + 1][k + i] += dp[j][k];
    return;
}

int main(){
    // std::cout << dp[10][10] << std::endl;
    solve();

    int n, s;
    while(true){
        std::cin >> n >> s;
        if(n == 0 && s == 0)
            break;
        std::cout << dp[n][s] << std::endl;
    }
    return 0;
}
