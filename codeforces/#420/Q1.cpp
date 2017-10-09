#include <cstdio>

constexpr int MAX_N = 50;

int N;
int field[MAX_N][MAX_N];

void solve();

int main(){
	scanf("%d", &N);

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			scanf("%d", &field[i][j]);
		}
	}

	solve();

	return 0;
}

void solve(){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			bool flag1 = false;
			for(int k = 0; k < N; ++k){
				bool flag2 = false;
				for(int l = 0; l < N; ++l){
					if(field[i][j] == field[k][j] + field[i][l] || field[i][j] == 1){
						flag2 = true;
						break;
					}	
				}

				if(flag2){
					flag1 = true;
					break;
				}
			}

			if(!flag1){
				puts("No");
				return;
			}
		}
	}

	puts("Yes");
}
