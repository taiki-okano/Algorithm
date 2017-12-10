#include <iostream>
#include <algorithm>
#include <limits>

constexpr int MAX_N = 50;
constexpr int MAX_L = 1000;
constexpr int INF = std::numeric_limits<int>::max();

int N;
int L[MAX_N];
int cl[MAX_N] = {};
int dp[MAX_N][MAX_N][3]; //min, max, diff
	
int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> N;

	for(int i = 0; i < N; ++i){
		std::cin >> L[i];
		if(i > 0){
			cl[i] = L[i] + cl[i - 1];
		}
		else{
			cl[i] = L[i];
		}
	}

	for(int i = 1; i < N; ++i){
		for(int j = 0; j < N; ++j){
			dp[i][j][0] = 0;
			dp[i][j][1] = INF;
			dp[i][j][2] = INF;
		}
	}

	for(int i = 0; i < N; ++i){
		dp[0][i][0] = 0;
		dp[0][i][1] = cl[i];
		dp[0][i][2] = 0;
	}

	int ans = INF;

	for(int i = 0; i < N - 1; ++i){
		for(int j = i; j < N - 1; ++j){
			for(int k = j + 1; k < N; ++k){
				if(k <= j){
					continue;
				}
				
				int min = dp[i][j][0];
				int max = dp[i][j][1];
				
				int tmp = cl[k] - cl[j];
				if(tmp > max){
					max = tmp;
				}
				if(tmp < min){
					min = tmp;
				}

				if(dp[i + 1][k][2] > max - min){
					dp[i + 1][k][0] = min;
					dp[i + 1][k][1] = max;
					dp[i + 1][k][2] = max - min;
					ans = std::min(ans, dp[i + 1][k][2]);
				}
			}
		}
	}

	std::cout << ans << std::endl;
}
