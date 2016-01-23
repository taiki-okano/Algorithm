#include <iostream>

#define MAX_WH 500

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

char field[MAX_WH][MAX_WH];
bool flag[MAX_WH][MAX_WH];
int W, H, sx, sy, gx, gy;

void solve();

void dfs(int _sx, int _sy);

int main(){
	std::cin >> W >> H;
	for(int i = 0; i < W; ++i){
		for(int j = 0; j < H; ++j){
			flag[i][j] = false;
			std::cin >> field[i][j];
			if(field[i][j] == 's')
				sx = i, sy = j;
			if(field[i][j] == 'g')
				gx = i, gy = j;
		}
	}
	
	solve();

	if(flag[gx][gy])
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;
	return 0;
}

void solve(){
	dfs(sx, sy);
	return;
}

void dfs(int _sx, int _sy){
	if(_sx < 0 || _sy < 0 || _sx >= W || _sy >= H)
		return;

	if(field[_sx][_sy] == '#')
		return;

	flag[_sx][_sy] = true;

	for(int i = 0; i < 4; ++i)
		dfs(_sx + dx[i], _sy + dy[i]);

	return;
}