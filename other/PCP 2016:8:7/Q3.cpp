#include <cstdio>
#include <algorithm>

constexpr int MAX_N = 100000;
constexpr int MAX_V = 10000;

int main(){
    int N, v[MAX_N]{}, dp[MAX_N]{};
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &v[i]);
    }
    dp[0] = v[0];
    dp[1] = v[1];
    for(int i = 2; i < N; ++i){
        dp[i] = std::max(dp[i - 2], dp[i - 3]) + v[i];
    }
    printf("%d\n", std::max(dp[N - 1], dp[N - 2]));
    return 0;
}