#include <iostream>
#include <vector>

constexpr int MAX_HW = 1000;

constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

int H, W;
char A[MAX_HW][MAX_HW][2];
bool used[MAX_HW][MAX_HW] = {};

int main(){

	std::cin >> H >> W;

	int black = 0, all = H * W;

	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			std::cin >> A[i][j][0];
			if(A[i][j][0] == '#'){
				++black;
			}
			A[i][j][1] = '.';
		}
	}

	int ans = 0;

	while(black < all){
		int cur = ans % 2;

		for(int i = 0; i < H; ++i){
			for(int j = 0; j < W; ++j){
				if(A[i][j][cur] == '#'){
					A[i][j][cur] = 'B';
					A[i][j][(cur + 1) % 2] = 'B';

					for(int k = 0; k < 4; ++k){
						int nh = i + dx[k];
						int nw = j + dy[k];


						if(nh < 0 || nh >= H || nw < 0 || nw >= W
								|| A[nh][nw][cur] == '#' || A[nh][nw][cur] == 'B'){
							continue;
						}

						if(!used[nh][nw]){
							++black;
							used[nh][nw] = true;
						}

						A[nh][nw][(cur + 1) % 2] = '#';
					}
				}
				else if(A[i][j][(cur + 1) % 2] != '#'){
					A[i][j][(cur + 1) % 2] = A[i][j][cur];
				}
			}
		}
		++ans;
	}

	std::cout << ans << std::endl;

	return 0;
}
