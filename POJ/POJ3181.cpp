#include <cstdio>
#include <algorithm>

#define MAX_N 1000
#define MAX_K 100
#define MOD 100000000000000000

int N, K;
unsigned long long dp[MAX_K + 1][MAX_N + 1][2];

void solve();

int main(){
	scanf("%d %d", &N, &K);
    solve();
	return 0;
}

void solve(){
	dp[0][0][1] = 1;

	for(int i = 1; i <= K; ++i){
		for(int j = 0; j <= N; ++j){
			dp[i][j][0] += dp[i - 1][j][0];
			dp[i][j][1] += dp[i - 1][j][1];
			dp[i][j][0] += dp[i][j][1] / MOD;
			dp[i][j][1] = dp[i][j][1] % MOD;
			if(j >= i){
				dp[i][j][0] += dp[i][j - i][0];
				dp[i][j][1] += dp[i][j - i][1];
				dp[i][j][0] += dp[i][j][1] / MOD;
				dp[i][j][1] = dp[i][j][1] % MOD;
			}
		}
	}

	if(dp[K][N][0] != 0){
		printf("%llu", dp[K][N][0]);
	}
	printf("%llu\n", dp[K][N][1]);
}
