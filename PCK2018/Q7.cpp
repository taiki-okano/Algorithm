#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef long long ll;

const ll MAX_N = 100000;
const ll MOD = 1000000007;

std::vector<ll> gate[26];
ll dp[MAX_N] = {};
ll qq[26];
int N;

int main(){

	std::string s, t;

	std::cin >> N >> s >> t;
	dp[0] = 1;
	for(int i = 0; i < N; ++i){
		dp[i] += qq[int(t[i] - 'a')];
		dp[i] %= MOD;
		ll c = ll(s[i] - 'a');
		qq[c] += dp[i];
		qq[c] %= MOD;
	}

	std::cout << dp[N - 1] % MOD << std::endl;

	return 0;
}
