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

	int A, B, C;

	std::cin >> A >> B >> C;

	int week_point = A * 7 + B;

	int ans = 0;

	while(true){

		if(C > 0){
			C -= A;
			if((ans + 1) % 7 == 0){
				C -= B;
			}
			++ans;
		}
		else{
			break;
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
