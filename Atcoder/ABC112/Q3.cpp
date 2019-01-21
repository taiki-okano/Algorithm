#include <iostream>
#include <cmath>

constexpr int MAX_XY = 101;

long long map[100][MAX_XY][MAX_XY] = {};

int main(){

	int N;

	std::cin >> N;

	for(int i = 0; i < N; ++i){

		long long x, y, h;

		std::cin >> x >> y >> h;

		if(h == 0){
			continue;
		}

		for(long long j = 0; j < MAX_XY; ++j){
			for(int k = 0; k < MAX_XY; ++k){

				map[i][j][k] = h + abs(x - j) + abs(y - k);

			}
		}
	}

	for(long long i = 0; i < MAX_XY; ++i){
		for(long long j = 0; j < MAX_XY; ++j){

			bool flag = true;

			long long tmp = 0;
			for(int k = 0; k < N; ++k){
				if(k == 0){
					tmp = map[k][i][j];
					if(tmp == 0){
						flag = false;
						break;
					}
				}

				if(tmp != map[k][i][j]){
					flag = false;
					break;
				}
			}

			if(flag){
				std::cout << i << ' ' << j << ' ' << tmp << std::endl;
				return 0;
			}

		}
	}

	return 0;
}
