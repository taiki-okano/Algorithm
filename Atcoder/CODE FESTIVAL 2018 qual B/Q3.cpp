#include <iostream>

constexpr int MAX_N = 1000;
constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};


int N;
char map[MAX_N][MAX_N];

int main(){

	std::cin >> N;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			map[i][j] = '.';
			if(i % 2 == 0){
				if(j % 4 == 0 ){
					map[i][j] = 'X';
				}
			}
			else{
				if((j + 2) % 4 == 0){
					map[i][j] = 'X';
				}
			}
		}
	}

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){

			if(map[i][j] == 'X') continue;

			bool flag = true;
			for(int k = 0; k < 4; ++k){

				int ni = i + dx[k];
				int nj = j + dy[k];

				if(ni < 0 || nj < 0 || ni >= N || nj >= N){
					continue;
				}

				if(map[ni][nj] == 'X'){
					flag = false;
					break;
				}
			}

			if(flag){
				map[i][j] = 'X';
			}
		}
	}

	int count = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(map[i][j] == 'X') ++count;
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "count : " << count << std::endl;

	return 0;
}

/*
X...X...X
..X...X..
X...X...X
..X...X..
X...X...X
..X...X..
X...X...X
..X...X..
*/
