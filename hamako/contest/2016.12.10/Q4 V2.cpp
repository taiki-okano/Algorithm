#include <cstdio>
#include <algorithm>

constexpr int MAX_HW = 100;

int H, W, ans = 0;
char map[MAX_HW / 2][MAX_HW / 2];
int memo[2][MAX_HW / 2][MAX_HW / 2];

int w_symmetry(int in);
int h_symmetry(int in);

int dfs(const bool& is_red, const int& w, const int& h);

void solve();

int main(){
	scanf("%d%d", &H, &W);
	for(int i = 0; i < H; ++i){
		scanf("\n");
		for(int j = 0; j < W; ++j){
			int x, y; char c;
			scanf("%c", &c);
			if(x > W / 2){
				x = w_symmetry(x);
			}
			if(y > H / 2){
				y = h_symmetry(y);
			}
			++map[x][y];
		}
	}
	solve();
	return 0;
}

void solve(){
	for(int i = 0; i < W; ++i){
		ans += map[i][0];
	}
	for(int i = 0; i < H; ++i){
		ans += map[0][i];
	}

	printf("%d\n", ans + std::min(dfs(true, W / 2, H / 2), dfs(false, W / 2, H / 2)));
}

int dfs(const bool& is_red, const int& w, const int& h){
	if(memo[is_red][w][h] != 0){
		return memo[is_red][w][h];
	}
	if(w == 0 || h == 0){
		return 0;
	}
	int res = MAX_HW * MAX_HW;
	res = std::min(res, 4 - map[w][h] + dfs(true, w - 1, h) + dfs(true, w, h - 1) - dfs(true, w, h));
	res = std::min(res, map[w][h] + dfs(false, w - 1, h) + dfs(false, w, h - 1) - dfs(false, w, h));
	return memo[is_red][w][h] = res;
}

int w_symmetry(int in){
	return W / 2 + (W / 2 - 1 - in);
}

int h_symmetry(int in){
	return H / 2  + (H / 2 - 1 - in);
}

