#include <cstdio>
#include <algorithm>

constexpr int MAX_B = 10000;

int M, B;

long long trees[MAX_B][MAX_B];

void solve();

int main(){
	scanf("%d%d", &M, &B);

	solve();

	return 0;
}

void solve(){
	for(int i = 0; i < B * M; ++i){
		for(int j = 0; j < B; ++j){
			trees[i][j] = i + j;
		}
	}

	for(int i = 0; i < B * M; ++i){
		for(int j = 0; j < B; ++j){
			trees[i][j] = trees[i][j - 1] + trees[i][j];
		}
	}

	for(int i = 1; i < B * M; ++i){
		for(int j = 0; j < B; ++j){
			trees[i][j] = trees[i - 1][j] + trees[i][j];
		}
	}

	long long ans = 0;
	for(int i = 0; i < B; ++i){
		int x = i * M, y = B - i;
		if(y < 0) break;

		ans = std::max(trees[x][y], ans);
	}

	printf("%lld\n", ans);
}
