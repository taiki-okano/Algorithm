#include <iostream>
#include <limits>

constexpr int INF = std::numeric_limits<int>::max();
constexpr int MAX_N = 100000;

int N, G;
int x[MAX_N], c[MAX_N], C[MAX_N];

int dp[MAX_N];

int main(){

	std::cin >> N >> G;

	for(int i = 0; i < N; ++i){
		dp[i] = INF;
	}

	for(int i = 0; i < N; ++i){
		std::cin >> x[i] >> c[i] >> C[i];
	}

	dp[0] = 0;
	for(int i = 0; i < N; ++i){

		for(int j = i + 1; j < N; ++j){

			if(x[j] > x[i] + c[i]){
				break;
			}

			dp[j] = std::min(dp[j], dp[i] + C[i]);
		}
	}

	if(dp[N - 1] == INF) std::cout << "-1" << std::endl;
	else std::cout << dp[N - 1] << std::endl;

	return 0;
}
