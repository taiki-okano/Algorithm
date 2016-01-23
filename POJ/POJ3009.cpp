#include <iostream>
#include <queue>

#define MAX_WH 20

typedef std::pair<int, int> P;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}

int W, H, sx, sy, gx, gy, ans;
char field[MAX_WH][MAX_WH];

void solve();

void bfs();

int main(){
	while(true){
		std::cin >> W >> H;
		for(int i = 0; i < W; ++W){
			for(int j = 0; j < H; ++j){
				std::cin >> field[i][j];
				if(field[i][j] == '2')
					sx = i, sy = j;
				else if(field[i][j] == '3')
					gx = i, gy = j;
			}
		}
		solve();
	}
	return 0;
}

void solve(){
	bfs();
	return;
}

void bfs(){
	int dis[MAX_WH][MAX_WH];
	std::queue<P> que;
	que.push(P(sx, sy));
	dis[sx][sy] = 0;

	while(!que.empty()){
		P p = que.front();
		que.pop();

		for(int i = 0; i < 4; ++i){
			int nx = p.first, ny = p.second;
			while(){
				nx += dx[i], ny += dy[i];
				if(nx >= 0 && ny >= 0 && nx < W && ny < H && field[nx][ny] == '1')
					break;

				
			}
			dis[nx][ny] = dis[p.first][p.second] + 1;
		}
	}
	return;
}
