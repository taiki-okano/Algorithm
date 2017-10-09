#include <iostream>
#include <queue>

typedef std::pair<int, int> P;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int field[2][4], sx, sy, ans;

void solve();

void bfs();

int main(){
	for(int i = 0; i < 2; ++i){
 		for(int j = 0; j < 4; ++j){
 			std::cin >> field[i][j];
 			if(field[i][j] == 0)
 				sx = i, sy = j;
 			solve();
 		}
 	}
	return 0;
}

void solve(){
 	ans = 0;
 	bfs();
	return;
}

void bfs(){
	std::queue<P> que;
 
	que.push(P(sx, sy));

	while(!que.empty()){
		P p = que.front(); que.pop();

		bool flag = false;
		for(int i = 0; i < 2; ++i){
			for(int j = 0; j < 4; ++j){
				if(field[i][j] != i * 4 + j){
					flag = true;
					break;
				}
			}
			if(flag)
				break;
		}
		if(!flag)
			return;
		/check answer

		for(int i =0 ; i < 4; ++i){
			int nx = p.first + dx[i], ny = p.second + dy[i];

			if(nx >= 0 && nx < 2 && ny >= 0 && ny < 2 && )
		}
	}
}