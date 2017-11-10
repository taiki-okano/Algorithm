#include <iostream>
#include <limits>
#include <queue>

typedef std::pair<int, int> Pair;

const int INF = 100000;
const int MAX_M = 50000;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int bfs();

int M;
int meteors[300 + 2][300 + 2] = {};
int dis[300 + 2][300 + 2] = {};

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	for(int i = 0; i < 300 + 2; ++i){
		for(int j = 0; j < 300 + 2; ++j){
			meteors[i][j] = INF;
			dis[i][j] = INF;
		}
	}

	std::cin >> M;

	for(int i = 0; i < M; ++i){
		int x, y, t;
		std::cin >> x >> y >> t;
		meteors[x][y] = std::min(t, meteors[x][y]);
		for(int j = 0; j < 4; ++j){
			int nx = x + dx[j], ny = y + dy[j];

			if(nx < 0 || ny < 0){
				continue;
			}
			meteors[nx][ny] = std::min(t, meteors[nx][ny]);
		}
	}

	std::cout << bfs() << std::endl;

	return 0;
}

int bfs(){
	std::queue<Pair> que;

	que.push(Pair(0, 0));

	dis[0][0] = 0;

	while(!que.empty()){
		Pair cur = que.front(); que.pop();
		
		for(int i = 0; i < 4; ++i){
			int nx = cur.first + dx[i], ny = cur.second + dy[i];
			
			if(nx < 0 || ny < 0){
				continue;
			}

			if(dis[nx][ny] != INF){
				continue;
			}

			if(meteors[nx][ny] <= dis[cur.first][cur.second] + 1){
				continue;
			}

			dis[nx][ny] = dis[cur.first][cur.second] + 1;
			if(meteors[nx][ny] == INF){
				return dis[nx][ny];
			}
			que.push(Pair(nx, ny));
		}
	}

	return -1;
}
