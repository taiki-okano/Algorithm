#include <iostream>
#include <algorithm>
#include <functional>

using ll = long long;

constexpr int MAX_N = 100000;

int N, K;
ll T[MAX_N];
ll diff[MAX_N - 1];

int main(){

	std::cin >> N >> K;

	for(int i = 0; i < N; ++i){

		std::cin >> T[i];

		if(i != 0) diff[i - 1] = T[i] - (T[i - 1] + 1);
	}

	std::sort(diff, diff + N, std::greater<ll>());

	ll ans = (T[N - 1] + 1) - T[0];

	for(int i = 0; i < K - 1; ++i){
		ans -= diff[i];
	}

	std::cout << ans << std::endl;

	return 0;
}
