#include <cstdio>
#include <cstring>
#include <algorithm>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)

#define MAX

constexpr int MAX_N = 20;

int N, ans = 0, bridges[MAX_N][MAX_N] = {};

int dfs(const int& pos = 0);

int main(){
	while(true){
		scanf("%d", &N);
		
		if(N == 0){
			break;
		}
		
		ans = 0;
		REP(i, N){
			REP(j, N){
				bridges[i][j] = 0;
			}
		}

		REP(i, N - 1){
			int a, b, t;
			scanf("%d%d%d", &a, &b, &t);

			--a, --b;
			bridges[a][b] = bridges[b][a] = t;

			ans += t * 2;
		}
		
		FOR(i, 1, N){
			int count = 0, tmp;
			REP(j, N){
				if(bridges[i][j] != 0){
					++count;
					tmp = j;
				}
			}
			if(count == 1){
				ans -= bridges[i][tmp] * 2;
				bridges[i][tmp] = bridges[tmp][i] = -1;
			}
		}

		printf("%d\n", ans - dfs());

	}
	return 0;
}

int dfs(const int& pos){
	int res = 0;
	
	REP(i, N){
		if(bridges[pos][i] != 0){
			bridges[i][pos] = 0;
			res = std::max(res, dfs(i) + bridges[pos][i]);
		}
	}

	return res;
}
