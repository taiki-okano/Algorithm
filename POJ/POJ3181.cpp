#include <iostream>

constexpr int MAX_N = 1000;
constexpr int MAX_K = 100;

int N, K;
int dp[MAX_N][MAX_K];

void solve();

int main(){
    solve();
}

void solve(){
    dp[1][1] = 1;
    for(int i = 1; i <= MAX_N; ++i){
        for(int j = 1; j <= i; ++j){
            if(i == 1 && j == 1){
                continue;
            }

        }
    }
}
