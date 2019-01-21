#include <iostream>
#include <algorithm>
#include <limits>

constexpr int INF = std::numeric_limits<int>::max();
constexpr int MAX_N = 50;
constexpr int MAX_L = 1000;

int main(){

	int N, L[MAX_N], cl[MAX_N] = {};

	std::cin >> N;

	for(int i = 0; i < N; ++i){

		std::cin >> L[i];

		if(i > 0){
			cl[i] = cl[i - 1] + L[i];
		}
		else{
			cl[i] = L[i];
		}
	}

	int dp[MAX_N][MAX_N][3];  // 0: Max, 1: min, 2: diff

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			dp[i][j][0] = 0;
			dp[i][j][1] = INF;
			dp[i][j][2] = INF;
		}
	}

	for(int i = 0; i < N; ++i){
		dp[0][i][0] = dp[0][i][1] = cl[i];
		dp[0][i][2] = 0;
	}

	int ans = INF;

	for(int i = 1; i < N; ++i){
		for (int j = i; j < N; ++j){
			for(int k = 1; j - k >= i - 1; ++k){

				int max = dp[i - 1][j - k][0];
				int min = dp[i - 1][j - k][1];

				int tmp = cl[j] - cl[j - k];

				if(tmp > max) max = tmp;
				if(tmp < min) min = tmp;

				if(max - min < dp[i][j][2]){
					dp[i][j][0] = max;
					dp[i][j][1] = min;
					dp[i][j][2] = max - min;
				}
			}
		}

		if(ans > dp[i][N - 1][2]){
			ans = dp[i][N - 1][0] - dp[i][N - 1][1];
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
