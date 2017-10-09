#include <cstdio>
#include <algorithm>

constexpr int MAX_HW = 300;
constexpr int INF = MAX_HW * MAX_HW;

int function(const int a, const int b);

int H, W;
int map[MAX_HW][MAX_HW];

int main(){
	scanf("%d %d", &H, &W);
	
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			scanf("%d", &map[i][j]);
		}
	}

	int ans = INF;
	for(int i = 1; i < H - 1; ++i){
		for(int j = 1; j <= i; ++j){
			ans = std::min(ans, function(j, i));
		}
	}

	printf("%d\n", ans);
	return 0;
}

int function(const int a, const int b){
	int res = INF;
	for(int i = a; i <= b; ++i){
		for(int j = 0; j < W; ++j){
			++map[i][j];
			map[i][j] %= 2;
		}
	}
	for(int d = 1; d < W - 1; ++d){
		for(int c = 1; c <= d; ++c){
			for(int i = c; i <= d; ++i){
				for(int j = 0; j < H; ++j){
					++map[j][i];
					map[j][i] %= 2;
				}
			}
			int sum = 0;
			for(int i = 0; i < H; ++i){
				for(int j = 0; j < W; ++j){
					sum += map[i][j];
				}
			}
			res = std::min(res, sum);
			for(int i = c; i <= d; ++i){
				for(int j = 0; j < H; ++j){
					++map[j][i];
					map[j][i] %= 2;
				}
			}
		}
	}
	for(int i = a; i <= b; ++i){
		for(int j = 0; j < W; ++j){
			++map[i][j];
			map[i][j] %= 2;
		}
	}
	return res;
}

