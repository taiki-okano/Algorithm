#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>

constexpr int MAX_HW = 25;
constexpr int INF = std::numeric_limits<int>::max();

int main(){
	int H, W;
	int A[MAX_HW][MAX_HW];

	std::cin >> H >> W;

	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			std::cin >> A[i][j];
		}
	}

	int ans = INF;
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			int sum = 0;
			for(int k = 0; k < H; ++k){
				for(int l = 0; l < W; ++l){
					int closer = std::min(abs(i - k), abs(j - l));
					sum += closer * A[k][l];
				}
			}
			ans = std::min(ans, sum);
		}
	}

	std::cout << ans << std::endl;
}
