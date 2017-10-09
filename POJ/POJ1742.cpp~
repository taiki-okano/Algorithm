#include <cstdio>
#include <cstring>

#define MAX_N 100
#define MAX_K 100000

int N, K, a[MAX_N], m[MAX_N];
int dp[MAX_K + 1];

void solve();

int main(){
	while(true){
		memset(dp, -1, sizeof(dp));

		scanf("%d%d", &N, &K);
		
		if(N == 0 && K == 0){
			break;
		}

		for(int i = 0; i < N; ++i){
			scanf("%d", &a[i]);
		}

		for(int i = 0; i < N; ++i){
			scanf("%d", &m[i]);
		}

		solve();
	}
	return 0;
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

	int ans = 0;
	for(int i = 1; i <= K; ++i){
		if(dp[i] >= 0){
			++ans;
		}
	}
	printf("%d\n", ans);
}
