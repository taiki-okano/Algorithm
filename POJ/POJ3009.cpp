#include <iostream>

#define MAX_W 20
#define MAX_H 20

int w, h;
int sx, sy;
int ans;
char field[MAX_W][MAX_H];

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

bool dfs(int x, int y, int count);

int main(){
	while(true){
		std::cin >> w >>h;
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				std::cin >> field[j][i];
				if(field[j][i] == '2')
					sx = j, sy = i; 
			}
		}

		if(dfs(sx, sy, 0))
			std::cout << ans << std::endl;
		else
			std::cout << "-1" << std::endl;
	}
	return 0;
}

bool dfs(int x, int y, int count){
	if(count > 10)
		return false;

	for(int i = 0; i < 4; ++i){
		int nx = x, ny = y;

		while(true){
			if(nx + dx[i] >= 0 && nx + dx[i] < MAX_W && ny + dy[i] >= 0 && ny + dy[i] < MAX_H){
				if(dfs(nx, ny, count + 1))
					return true;
				else
					return false;
			}
			if(field[nx + dx[i]][ny + dy[i]] == '1'){
				field[nx + dx[i]][ny + dy[i]] == '0';
				if(dfs(nx, ny, count + 1))
					return true;
				else{
					field[nx + dx[i]][ny + dy[i]] == '1';
					return false;
				}
			}
			if(field[nx + dx[i]][ny + dy[i]] == '3'){
				ans = count + 1;
				return true;
			}
		}
		return false;
	}
}