#include <iostream>
#include <algorithm>
#include <limits>

constexpr int MAX_NM = 1000;
constexpr long long INF = 10000000000;

int M, N, A, B;
long long csum[MAX_NM + 1][MAX_NM + 1];

int main(){

	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> M >> N >> A >> B;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){

			long long cost;

			std::cin >> cost;

			if(cost == -1) csum[i + 1][j + 1] = INF;
			else csum[i + 1][j + 1] = cost;

			csum[i + 1][j + 1] += csum[i][j + 1] + csum[i + 1][j] - csum[i][j];
		}
	}

	long long ans = INF;

	for(int i = B; i <= N; ++i){
		for(int j = A; j <= M; ++j){
			ans = std::min(ans, csum[i][j] - csum[i - B][j] - csum[i][j - A] + csum[i - B][j - A]);
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
