#include <iostream>
#include <algorithm>

constexpr int MAX_NM = 1000;

using Pair = std::pair<int, int>;

int main(){

	int N, M;
	int A[MAX_NM];
	Pair dp[MAX_NM][MAX_NM] = {};

	std::cin >> N >> M;

	for(int i = 0; i < N; ++i){
		std::cin >> A[i];
	}

	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			if(j > 0){
				dp[i][j].first = std::min(dp[i][j - 1].first, A[j]);
				dp[i][j].second = std::max(dp[i][j - 1].second, A[j]);
			}
			else{
				dp[i][j].first = std::min(dp[i][j].first, A[j]);
				dp[i][j].second = std::max(dp[i][j].second, A[j]);
			}
		}
	}
}
