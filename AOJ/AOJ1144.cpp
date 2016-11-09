#include <cstdio>
#include <algorithm>
#include <queue>
#include <limits>

typedef std::pair<int, int> P;

constexpr int MAX_WH = 20;
constexpr int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int W, H;
int sx, sy, gx, gy;
int map[MAX_WH][MAX_WH];

int dfs(const P& pos, const bool can_reach_there[MAX_WH][MAX_WH], const int count = 0);

void solve();

int main(){
	while(true){
		scanf("%d%d", &W, &H);
		if(W == 0 && H == 0){
			break;
		}
		for(int i = 0; i < W; ++i){
			for(int j = 0; j < H; ++j){
				scanf("%d", &map[i][j]);
				if(map[i][j] == 2){
					sx = i, sy = j;
				}
				if(map[i][j] == 3){
					gx = i, gy = j;
				}
			}
		}
		solve();
	}
	return 0;
}

void solve(){
	//debug
	/*
	std::vector<P> v_debug{P(0, 0)};
	if(can_reach_there(P(0, 0), v_debug)){
		puts("Correct.");
	}
	else{
		puts("Incorrect.");
	}
	*/
	bool array[MAX_WH][MAX_WH];
	for(int i = 0; i < W; ++i){
		for(int j = 0; j < H; ++j){
			array[i][j] = false;
		}
	}
	printf("%d\n", dfs(P(sx, sy), array));
}

int dfs(const P& pos, const bool can_reach_there[MAX_WH][MAX_WH], const int count){
	if(count > 10){
		return -1;
	}
	if(pos.first == gx && pos.second == gy){
		//debug
		/*
		for(auto& x : broken_blocks){
			printf("P(%d, %d) has added to the vector.\n", x.first, x.second);
		}
		printf("Vector size is %lu.\n", broken_blocks.size());
		*/
		return 0;
	}
	bool _can_reach_there[MAX_WH][MAX_WH];
	for(int i = 0; i < W; ++i){
		for(int j = 0; j < H; ++j){
			if(can_reach_there[i][j]){
				_can_reach_there[i][j] = true;
			}
			else{
				_can_reach_there[i][j] = false;
			}
		}
	}
	int res = std::numeric_limits<int>::max();
	for(int i = 0; i < 4; ++i){
		for(int j = 1; ; ++j){
			int nx = pos.first + dx[i] * j, ny = pos.second + dy[i] * j;
			if(nx < 0 || ny < 0 || nx >= W || ny >= H){
				if(j == 1){
					break;
				}
				int tmp = dfs(P(nx - dx[i], ny - dy[i]), _can_reach_there, count + 1);
				if(tmp != -1){
					res = std::min(res, tmp + 1);
				}
				break;
			}
			if(map[nx][ny] == 1 && !_can_reach_there[nx][ny]){
				if(j == 1){
					break;
				}
				_can_reach_there[nx][ny] = true;
				int tmp = dfs(P(nx - dx[i], ny - dy[i]), _can_reach_there, count + 1);
				if(tmp != -1){
					res = std::min(res, tmp + 1);
				}
				break;
			}
		}
	}
	if(res == std::numeric_limits<int>::max()){
		return -1;
	}
	return res;
}
