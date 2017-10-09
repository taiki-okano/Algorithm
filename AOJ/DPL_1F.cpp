#include <cstdio>
#include <algorithm>
#include <limits>

constexpr int MAX_NV = 100;
constexpr long MAX_W = 1000000000;
constexpr long INF = std::numeric_limits<long>::max();

int main(){
	int N, W, v[MAX_NV], w[MAX_NV];
	long dp[MAX_NV * MAX_NV + 1]{};

	scanf("%d%d", &N, &W);

	for(int i = 0 ; i <= N * MAX_NV; ++i){
		dp[i] = INF;
	}

	for(int i = 0; i < N; ++i){
		scanf("%d%d", &v[i], &w[i]);
	}

	dp[0] = 0;

	for(int i = 0; i < N; ++i){
		for(int j = N * MAX_NV; j >= 0; --j){
			if(j >= v[i]){
				if(dp[j - v[i]] != INF && dp[j - v[i]] + w[i] <= W){
					dp[j] = std::min(dp[j - v[i]] + w[i], dp[j]);
				}
			}
		}
	}

	int ans = 0;

	for(int i = 0; i <= MAX_NV * N; ++i){
		if(dp[i] != INF){
			ans = i;
		}
	}
	
	printf("%d\n", ans);

	return 0;
}
