#include <iostream>

constexpr int MAX_HW = 400;
constexpr int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int H, W;
long long memo[MAX_HW][MAX_HW];
bool used[MAX_HW][MAX_HW];
long long black, white;
char map[MAX_HW][MAX_HW] = {};

void dfs(int h, int w, int count = 0);

int main(){

	std::cin >> H >> W;

	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			memo[i][j] = -1;
			std::cin >> map[i][j];
		}
	}

	long long ans = 0;
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){

			char c = map[i][j];

			if(c == '#'){
				black = 0, white = 0;
				dfs(i, j);
				ans += black * white;
			}
		}
	}

	std::cout << ans << std::endl;

	return 0;
}

void dfs(int h, int w, int count){

	if(map[h][w] == '#'){
		++black;
	}
	else if(map[h][w] == '.'){
		++white;
	}

	map[h][w] = 'x';

	for(int i = 0; i < 4; ++i){

		int nh = h + dx[i];
		int nw = w + dy[i];

		if(nh >= H || nw >= W || nh < 0 || nw < 0){
			continue;
		}

		char next = (count % 2 == 0 ? '.' : '#');
		if(map[nh][nw] == next){
			dfs(nh, nw, count + 1);
		}
	}
}
