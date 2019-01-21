#include <iostream>
#include <algorithm>

constexpr int MAX_N = 200000;

int L, N;
int X[MAX_N];

int main(){

	std::cin >> L >> N;

	for(int i = 0; i < N; ++i){
		std::cin >> X[i];
	}

	int ans = 0;

	if(N == 1){

		std::cout << std::max(X[0], L - X[0]) << std::endl;

		return 0;
	}

	for(int i = 0; i < N; ++i){

		int res = 0;

		int max = i, min = i;

		while(max < N && min > 0){

			if(max == min){
				res = std::max(L - X[max], X[max]);
			}
			else{
				res += (L - X[max]) * 2 + X[min] * 2;
			}

			++max, --min;
		}

		ans = std::max(ans, res);
	}

	std::cout << ans << std::endl;

	return 0;
}
