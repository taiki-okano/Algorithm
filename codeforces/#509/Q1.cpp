#include <iostream>
#include <algorithm>

constexpr long long MAX_A = 1000000000;

int main(){

	long long N;

	long long min = MAX_A, max = 0;

	std::cin >> N;

	for(int i = 0; i < N; ++i){

		long long input;

		std::cin >> input;

		min = std::min(min, input);
		max = std::max(max, input);
	}

	std::cout << max - min + 1 - N << std::endl;

	return 0;
}
