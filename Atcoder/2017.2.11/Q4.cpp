#include <cstdio>
#include <algorithm>
#include <limits>

constexpr int MAX_N = 40;
constexpr int MAX_AB = 10;

int n, ma, mb;
int a[MAX_N], b[MAX_N], c[MAX_N];
int dp[MAX_AB * MAX_N + 1][MAX_AB * MAX_N + 1];

int gcd(int a, int b){
	if(a == b) return a;
	return gcd(b, a % b);
}

int main(){
	scanf("%d%d%d", &n, &ma, &mb);

	for(int i = 0; i < n; ++i){
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}

	for(int i = 0; i < MAX_AB * MAX_N; ++i){
		for(int j = 0; j < MAX_AB * MAX_N; ++j){
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= MAX_AB * (MAX_N - 1); ++j){
			for(int k = 0; k <= MAX_AB * (MAX_N - 1); ++k){
				if(dp[j][k] >= 0){
					dp[j + a[i]][k + b[i]] += c[i];
				}
			}
		}
	}

	int ans = std::numeric_limits<int>::max();

	for(int i = 0; i <= MAX_AB * MAX_N; ++i){
		for(int j = 0; j <= MAX_AB * MAX_N; ++j){
			if(dp[i][j] >= 0 && i / gcd(i, j) == ma && j / gcd(i, j) == mb){
				ans = std::min(ans, dp[i][j]);
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
