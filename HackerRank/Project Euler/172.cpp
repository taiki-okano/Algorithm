#include <cstdio>
#include <cstring>
#include <algorithm>

#define rep(i, a), for(int i = 0; i < (a); ++i)

using ull = unsigned long long;

constexpr int MAX_MT = 100000;
constexpr ull MOD = 1000000007;

ull memo[10][MAX_MT];
ull fact[MAX_MT];
int M, T;

ull permutation();

ull dp(int i, int x);

int main() {
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < 11; ++i){
		dp[i][0] = 1;
	}

	fact[0] = 1;
	for(int i = 1; i <= MAX_MT; ++i){
		fact[i] = fact[i - 1] * i % MOD;
	}

    scanf("%d%d", &M, &T);
    
	rep(I, T){
		int k;
		scanf("%d", &k);
		printf("%d", dp())
	}
    return 0;
}

ull dp(int i, int x){
	if(i >= 1)
	ull res = 0;
}
