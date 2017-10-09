#include <iostream>

constexpr int MAX_N = 100000, MAX_M = 20;

int N, M, c_sum[MAX_M][MAX_N];

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M;
	
	for(int i = 0; i < N; ++i){
		int input;
		std::cin >> input;
		if(i > 0){
			c_sum[input][i] = c_sum[input][i - 1] + 1;
		}
		else{
			c_sum[input][i] = 1;
		}
	}

	return 0;
}
