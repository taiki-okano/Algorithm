#include <iostream>
#include <algorithm>

typedef unsigned long long ull;

constexpr int MAX_N = 1001, MAX_K = 101;
constexpr ull MOD = 100000000000000000;

int n, k;
ull dp[MAX_N + 16][MAX_K + 16][2]; //KドルまでのコインでNドルを支払う時の払い方。

void fill_dp();

void solve();

int main(){
    std::cin >> n >> k;
    solve();
    return 0;
}

void solve(){
    dp[1] = 1;
}

void fill_dp(){

}