#include <cstdio>

constexpr int MAX_N = 500;
constexpr int MAX_M = 10000;

int dfs(int n = 0, int depth = 0);

int N, M;
bool friends[MAX_N][MAX_N];
bool isSent[MAX_N];

int main(){
	while(true){
		scanf("%d%d", &N, &M);
		if(N == 0 && M == 0){
			break;
		}
		for(int i = 0; i < N; ++i){
			isSent[i] = false;
			for(int j = 0; j < N; ++j){
				friends[i][j] = false;
			}
		}
		for(int i = 0; i < M; ++i){
			int a, b;
			scanf("%d%d", &a, &b);
			--a, --b;

			friends[a][b] = friends[b][a] = true;
		}
		
		printf("%d\n", dfs());
	}
	return 0;
}

int dfs(int n, int depth){
	if(depth == 2){
		if(isSent[n]){
			return 0;
		}
		else{
			return 1;
		}
	}

	isSent[n] = true;

	int res = 1;
	if(depth == 0){
		--res;
	}

	for(int i = 0; i < N; ++i){
		if(friends[n][i] && !isSent[i]){
			res += dfs(i, depth + 1);
		}
	}

	return res;
}
