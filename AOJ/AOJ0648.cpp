#include <iostream>
#include <algorithm>
#include <limits>

using ll = long long;

constexpr int MAX_N = 500000;

int N;
std::pair<ll, ll> arts[MAX_N];

int main(){

	std::cin >> N;

	for(int i = 0; i < N; ++i){

		std::cin >> arts[i].first >> arts[i].second;

	}

	std::sort(arts, arts + N);

	for(int i = 0; i < N; ++i){
		if(i > 0){
			arts[i].second += arts[i - 1].second;
		}
	}

	ll x = -arts[0].first;
	ll ans = arts[0].second;

	for(int i = 1; i < N; ++i){

		x = std::min(x, arts[i - 1].second - arts[i].first);
		ans = std::max(ans, arts[i].second - arts[i].first - x);

	}

	std::cout << ans << std::endl;

	return 0;
}
