#include <cstdio>
#include <cstring>

constexpr int MAX_N = 100;
constexpr int MAX_K = 100000;

int N, K, a[MAX_N], m[MAX_N];
int dp[MAX_K + 1];

void solve();

int main(){
	memset(dp, -1, sizeof(dp));

	scanf("%d%d", &N, &K);

	for(int i = 0; i < N; ++i){
		scanf("%d%d", &a[i], &m[i]);
	}

	solve();
}

void solve(){
	dp[0] = 0;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j <= K; ++j){
			if(dp[j] >= 0){
				dp[j] = m[i];	
			}
			else if(j < a[i] || dp[j - a[i]] <= 0){
				dp[j] = -1;
			}
			else{
				dp[j] = dp[j - a[i]] - 1;
			}
		}
	}

	if(dp[K] >= 0){
		puts("YES");
	}
	else{
		puts("NO");
	}
}