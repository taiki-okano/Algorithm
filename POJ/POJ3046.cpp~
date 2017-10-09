#include <cstdio>
#include <cstring>

#define MAX_N 100
#define MAX_T 1000

int T, A, S, B, m[MAX_T];

void solve();

int main(){
	scanf("%d%d%d%d", &T, &A, &S, &B);

	for(int i = 0; i < A; ++i){
		int in;
		scanf("%d", &in);
		++m[in];
	}

	solve();

	return 0;
}

void solve(){
	int dp[MAX_T]; //dp[i] : iを作るのに余った、アリの数
	memset(dp, -1, sizeof(dp));

	dp[0] = 0;
	
	for(int i = 0; i < A; ++i){
		for(int j = 0; j <= B; ++j){
			if(dp[j] >= 0){
				dp[j] = m[i];
			}
			else if()
		}
	}
}
