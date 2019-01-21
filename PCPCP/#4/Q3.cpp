#include <iostream>
#include <queue>

using P = std::pair<int, int>;

constexpr int MAX_WH = 2000;

constexpr int dx[] = {1, -1, 1, -1, 0, 0, 1, -1};
constexpr int dy[] = {1, -1, -1, 1, 1, -1, 0, 0};

int H, W, Q;
int ans = 0;

int map[MAX_WH][MAX_WH] = {};

void bfs(int x, int y, int d);

int main(){

	std::cin >> H >> W >> Q;

	while(Q--){
		int x, y, d;
		std::cin >> x >> y >> d;

		bfs(x, y, d);

		std::cout << ans << std::endl;

		ans = 0;
	}

	return 0;
}

void bfs(int x, int y, int d){

	if(map[x][y] >= d){
		return;
	}

	std::queue<P> que;

	que.push(P(x, y));

	ans += (d - map[x][y]);

	map[x][y] = d;

	while(!que.empty()){

		P p = que.front(); que.pop();

		for(int i = 0; i < 8; ++i){
			int px = p.first, py = p.second;
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if(nx < 0 || ny < 0 || nx >= W || ny >= H || map[nx][ny] >= map[px][py] - 1){
				continue;
			}

			ans += (map[px][py] - 1) - map[nx][ny];

			map[nx][ny] = map[px][py] - 1;

			que.push(P(nx, ny));

		}
	}
}

/*
5 4 3 2 1
4 4 3 2 1
3 3 3 2 1
2 2 2 2 1
1 1 1 1 1
 * */
