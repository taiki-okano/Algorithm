#include <cstdio>
#include <algorithm>

constexpr int MAX_N = 100000;
constexpr int MAX_V = 10000;

int main(){
    int N, v[MAX_N], dp[MAX_N]{};
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &v[i]);
    }
    dp[0] = v[0];
    dp[1] = v[1];
    for(int i = 2; i < N; ++i){
        int max = 0;
        for(int j = 0; j < i - 1; ++j){
            max = std::max(max, dp[i]);
        }
        dp[i] = max + v[i];
    }
    printf("%d\n", dp[N]);
    return 0;
}