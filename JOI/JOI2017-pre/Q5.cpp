#include <iostream>
#include <queue>

typedef std::pair<int, int> Pair;

constexpr int MAX_HW = 1000;
constexpr int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

int H, W;
int field[MAX_HW][MAX_HW];
int a[MAX_HW][MAX_HW];

void bfs(int h, int w);

void solve();

int main(){
	std::ios::sync_with_stdio(false);
	std::cin >> H >> W;
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			std::cin >> field[i][j];
		}
	}
	solve();

	return 0;
}

void solve(){
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			bool flag = true;
			for(int k = 0; k < 4; ++k){
				int nh = i + dx[k], nw = j + dy[k];
				if(nh >= 0 && nw >= 0 && nh < H && nw < W && field[nh][nw] < field[i][j]){
					flag = false;
					break;
				}
			}
			if(flag){
				bfs(i, j);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			if(a[i][j] > 1){
				++ans;
			}
		}
	}
	std::cout << ans << std::endl;
}

void bfs(int h, int w){
	bool flag[MAX_HW][MAX_HW];

	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			flag[i][j] = true;
		}
	}

	std::queue<Pair> que;
	que.push(Pair(h, w));
	
	while(!que.empty()){
		Pair p = que.front(); que.pop();
		
		bool tmp = true;
		for(int i = 0; i < 4; ++i){
			int nh = p.first + dx[i], nw = p.second + dy[i];
			if(nh >= 0 && nw >= 0 && nh < H && nw < W && field[nh][nw] > field[p.first][p.second] && flag[nh][nw]){
				flag[nh][nw] = false;
				++a[nh][nw];
				que.push(Pair(nh, nw));
			}
		}
	}
}
