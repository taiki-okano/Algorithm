#include <iostream>
#include <algorithm>

using ll = long long;

constexpr int MAX_N = 100000;

int N, K;
ll csum_A[MAX_N];

int main(){

	while(true){

		std::cin >> N >> K;

		if(N == 0 && K == 0) break;

		for(int i = 0; i < N; ++i){

			ll input;

			std::cin >> input;

			if(i == 0) csum_A[i] = input;
			else csum_A[i] = csum_A[i - 1] + input;
		}

		ll ans = csum_A[K - 1];

		for(int i = 0; i < N - K; ++i){

			ans = std::max(ans, csum_A[i + K] - csum_A[i]);

		}

		std::cout << ans << std::endl;
	}

	return 0;
}
