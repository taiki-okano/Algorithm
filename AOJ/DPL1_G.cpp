#include <cstdio>
#include <cstring>
#include <algorithm>

typedef std::pair<int, int> Pair;

constexpr int MAX_N = 100;
constexpr int MAX_MW = 10000;

int N, W, v[MAX_N], m[MAX_N], w[MAX_N];
Pair dp[MAX_MW + 1]; //first : v, second : m

void solve(){
	dp[0] = Pair(0, 0);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < W; ++j){
			if(dp[j].second >= 0){
				dp[j].second = m[i];
			}
		}
	}
}

int main(){
	std::fill(dp, dp + MAX_NW + 1, Pair(-1, -1));

	scanf("%d%d", &N, &W);

	for(int i = 0; i < N; ++i){
		scanf("%d%d%d", &v[i], &m[i], &w[i]);
	}

	solve();

    return 0;
}
