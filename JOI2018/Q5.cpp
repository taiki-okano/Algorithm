#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>

using pair = std::pair<int, int>;

constexpr int MAX_HW = 30;
constexpr int INF = std::numeric_limits<int>::max();
constexpr int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int bfs();

int H, W;
int field[MAX_HW][MAX_HW];
int dis[MAX_HW][MAX_HW];
int wdis[MAX_HW][MAX_HW];
int ans = INF;

int main(){
	std::cin >> H >> W;
	
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			dis[i][j] = INF;
			wdis[i][j] = INF;
			std::cin >> field[i][j];
		}
	}

	std::cout << bfs() << std::endl;

	return 0;
}

int bfs(){
	std::queue<pair> que;
	que.push(pair(0, 0));
	dis[0][0] = 0;
	wdis[0][0] = 0;

	while(!que.empty()){
		pair cur = que.front();
		que.pop();

		int h = cur.first, w = cur.second;

		if(h == H - 1 && w == W - 1){
			ans = std::min(dis[h][w], ans);
		}

		for(int i = 0; i < 4; ++i){
			int nh = h + dy[i], nw = w + dx[i];
			if(nh >= 0 && nw >= 0 && nh < H && nw < W){
				if(std::min(dis[nh][nw], ans) > dis[h][w] + field[nh][nw] * (2 * wdis[h][w] + 1)){
					wdis[nh][nw] = wdis[h][w] + 1;
					dis[nh][nw] = dis[h][w] + field[nh][nw] * (2 * wdis[h][w] + 1);
					que.push(pair(nh, nw));
				}
			}
		}
	}

	return dis[H - 1][W - 1];
}
