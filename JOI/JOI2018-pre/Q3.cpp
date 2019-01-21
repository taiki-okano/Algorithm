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
constexpr int LL_INF = std::numeric_limits<long long>::max();

using Pair = std::pair<int, int>;

int main(){

	int N;
	std::string S;

	std::cin >> N >> S;

	int ans = 0;
	for(int i = 0; i < S.length(); ++i){
		if((S[i] == 'X' && S[i + 1] == 'O') || (S[i] == 'O' && S[i + 1] == 'X')){
			++ans;
			++i;
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
