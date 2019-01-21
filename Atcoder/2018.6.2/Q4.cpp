#include <iostream>
#include <algorithm>

constexpr int MAX_NM = 1000;

int H, W, N, M;
char stamps[MAX_NM][MAX_NM];

int main(){

	std::cin >> H >> W >> N >> M;

	int b_count = 0;
	int h_count = 0;
	int left_black = MAX_NM;
	int right_black = 0;
	for(int i = 0; i < N; ++i){
		bool flag = false;
		for(int j = 0; j < M; ++j){
			std::cin >> stamps[i][j];
			if(stamps[i][j] == '#'){
				left_black = std::min(j, left_black);
				right_black = std::max(j, right_black);
				++b_count;
				flag = true;
			}
		}
		if(flag){
			++h_count;
		}
	}

	if(b_count == 0){
		std::cout << 0 << std::endl;
	}
	else{
		std::cout << long(b_count
			+ h_count * (W - M)
			+ (W - left_black - (M - right_black - 1)) * (H - N))	
				<< std::endl;
	}

	return 0;
}
