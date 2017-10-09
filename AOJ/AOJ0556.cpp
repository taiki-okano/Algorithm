#include <cstdio>
#include <cstdlib>
#include <algorithm>

using ll = long long;

constexpr ll MAX_N = 1000000000;
constexpr ll MAX_K = 1000;

int main(){
	ll N, K;
	scanf("%llu%llu", &N, &K);

	for(int i = 0; i < K; ++i){
		ll a, b;
		std::scanf("%llu%llu", &a, &b);
		ll x = std::min(a, std::abs(N - a) + 1);
		ll y = std::min(b, std::abs(N - b) + 1);
		ll tmp = std::min(x, y) % 3;
		if(tmp == 0){
			tmp = 3;
		}
		std::printf("%llu\n", tmp);
	}

	return 0;
}
