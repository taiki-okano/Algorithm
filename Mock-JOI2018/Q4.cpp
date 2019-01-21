#include <iostream>
#include <algorithm>
#include <cstring>

constexpr int MAX_NM = 1000;

int main(){

	int N, H;

	std::cin >> N >> H;

	int h[MAX_NM] = {}, w[MAX_NM] = {};
	int dp[2][MAX_NM + 1] = {};

	for(int i = 0; i < N - 1; ++i){
		std::cin >> w[i] >> h[i];
	}

	for(int i = 0; i < N - 1; ++i){
		int s = i % 2, t = (s + 1) % 2;
		for(int j = 0; j < H; ++j){
			int tmp = std::min(H, j + h[i]);
			if(j == 0 || (j > 0 && dp[t][j] != 0)){
				if(dp[s][tmp] == 0){
					dp[s][tmp] = dp[t][j] + w[i] * (i + 1);
				}
				else{
					dp[s][tmp] = std::min(dp[s][tmp], dp[t][j] + w[i] * (i + 1));
				}
			}
		}
		memcpy(dp[t], dp[s], sizeof(int) * (H + 1));
	}

	if(dp[0][H] == 0){
		std::cout << -1 << std::endl;
	}
	else{
		std::cout << dp[0][H] << std::endl;
	}
}
