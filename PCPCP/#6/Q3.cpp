#include <iostream>
#include <algorithm>

constexpr int MAX = 1000;

int N, M, K;
int A[MAX];

int dp[MAX + 1];

int main(){

	std::cin >> N >> M >> K;

	for(int i = 0; i < N; ++i){
		std::cin >> A[i];
	}

	for(int i = 0; i < N; ++i){
		for(int j = N; j >= 0; --j){
			if(j > 0){
				if(j - 1 >= M){
					dp[j] = std::max(dp[j], dp[j - 1] + A[i] - K);
				}
				else{
					dp[j] = std::max(dp[j], dp[j - 1] + A[i]);
				}
			}
		}
	}

	int ans = 0;

	for(int i = 0; i <= N; ++i){
		ans = std::max(ans, dp[i]);
	}

	std::cout << ans << std::endl;

	return 0;
}

// DPが200点しかないの、さすがって感じです。
