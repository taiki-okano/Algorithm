#include <iostream>
#include <algorithm>

constexpr int MAX_HW = 1000;
constexpr int INF = 1000 * 1000;

constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

int H, W;
int dis[MAX_HW][MAX_HW];

int main(){

	std::cin >> H >> W;

	int black = 0, all = H * W;

	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			char input;
			std::cin >> input;

			if(input == '#'){
				dis[i][j] = 0;
			}
			else{
				dis[i][j] = INF;
			}
		}
	}

	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){

			int min = INF;

			for(int k = 0; k < 4; ++k){
				int nh = i + dx[k], nw = j + dy[k];

				if(nh >= 0 && nw >= 0 && nh < H && nw < W){
					min = std::min(min, dis[nh][nw]);
				}
			}

			dis[i][j] = std::min(dis[i][j], min + 1);
		}
	}

	for(int i = H - 1; i >= 0; --i){
		for(int j = W - 1; j >= 0; --j){

			int min = INF;

			for(int k = 0; k < 4; ++k){
				int nh = i + dx[k], nw = j + dy[k];

				if(nh >= 0 && nw >= 0 && nh < H && nw < W){
					min = std::min(min, dis[nh][nw]);
				}
			}

			dis[i][j] = std::min(dis[i][j], min + 1);
		}
	}

	int ans = 0;
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			ans = std::max(ans, dis[i][j]);
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
