#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cmath>
#include <cstring>
#include <cstdlib>

constexpr int INF = std::numeric_limits<int>::max();
constexpr long long LL_INF = std::numeric_limits<long long>::max();

constexpr long long MAX_N = 100;
constexpr long long MOD = 10007;

using Pair = std::pair<int, int>;

long long seats[MAX_N];
long long country[MAX_N];
long long N;
long long A[MAX_N];
long long sum;

long long dfs(long long n = 0);

int main(){

	std::cin >> N;

	for(int i = 0; i < N; ++i){
		std::cin >> A[i];
		sum += A[i];
	}

	long long ans = dfs();

	for(int i = 0; i < N; ++i){
		ans = ans * A[i] % MOD;
	}

	std::cout << ans << std::endl;

	return 0;
}

long long dfs(long long n){

	if(n == sum){
		return 1;
	}

	long long res = 0;

	if(n == 0){
		for(int i = 0; i < N; ++i){
			seats[n] = i;
			++country[i];
			res += dfs(n + 1);
			--country[i];
		}
	}
	else{
		for(int i = 0; i < N; ++i){

			if(abs(seats[n - 1] - i) <= 1 || country[i] >= A[i]){
				continue;
			}

			seats[n] = i;
			++country[i];
			res += dfs(n + 1);
			--country[i];
		}
	}

	return res;
}
