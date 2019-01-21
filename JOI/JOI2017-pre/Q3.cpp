#include <iostream>

constexpr int MAX = 100;

int main(){
	int N, M, D, ans = 0;
	scanf("%d %d %d", &N, &M, &D);

	char map[MAX][MAX];

	for(int i = 0; i < N; ++i){
		scanf("\n");
		for(int j = 0; j < M; ++j){
			scanf("%c", &map[i][j]);
		}
	}

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			bool flag = true;
			for(int k = 0; k < D; ++k){
				if(map[i + k][j] == '#' || i + k >= N){
					flag = false;
					break;
				}
			}
			ans += flag;
			flag = true;
			for(int k = 0; k < D; ++k){
				if(map[i][j + k] == '#' || j + k >= M){
					flag = false;
					break;
				}
			}
			ans += flag;
		}
	}

	printf("%d\n", ans);

	return 0;
}
