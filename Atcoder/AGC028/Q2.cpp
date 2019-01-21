#include <iostream>
#include <algorithm>

using ll = long long;

constexpr ll MOD = 1000000007;
constexpr int MAX_N = 100000;

ll N;
ll P[MAX_N];

ll ext_gcd(ll a, ll b, ll &x, ll &y){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	ll d = ext_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

ll inv_mod(ll a, ll m){
	ll x, y;
	ext_gcd(a, m, x, y);
	x %= m;
	if(x < 0) x += m;
	return x;
}

int main(){

	std::cin >> N;

	for(int i = 0; i < N; ++i){
		ll x = inv_mod(i + 1, MOD);
		if(i > 0) P[i] = x;
		else P[i] = P[i - 1] + x;
		std::cout << P[i] % MOD << std::endl;
	}

	ll ans = 0;
	for(int i = 0; i < N; ++i){
		ll input;
		std::cin >> input;
		ans += input * (P[i] + P[N - 1] - P[i]) % MOD;
		ans %= MOD;
	}

	std::cout << ans << std::endl;

	return 0;
}
