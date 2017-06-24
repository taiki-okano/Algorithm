#include <iostream>
#include <algorithm>

constexpr int MAX_AB = 10000;

int dp(int a, int b);

int A, B, C, memo[MAX_AB][MAX_AB];

int main(){
    std::cin >> A >> B >> C;
    int tmp = dp(0, 0);
    if(tmp >= MAX_AB){
        std::cout << "-1" << std::endl;
    }
    else{
        std::cout << tmp << std::endl;
    }
    return 0;
}

int dp(int a, int b){
    if(memo[a][b] != 0){
        return memo[a][b];
    }
    else{
        memo[a][b] = MAX_AB;
    }
    if(a == C || b == C){
        return 0;
    }
    int res = MAX_AB;
    if(a != A){
        res = std::min(res, dp(A, b));
    }
    if(b != B){
        res = std::min(res, dp(a, B));
    }
    if(a != 0){
        res = std::min(res, dp(0, b));
    }
    if(b != 0){
        res = std::min(res, dp(a, 0));
    }
    int max = a + b;
    if(max <= A){
        res = std::min(res, dp(max, 0));
    }
    else{
        res = std::min(res, dp(A, max - A));
    }
    if(max <= B){
        res = std::min(res, dp(0, max));
    }
    else{
        res = std::min(res, dp(max - B, B));
    }
    return memo[a][b] = res + 1;
}

