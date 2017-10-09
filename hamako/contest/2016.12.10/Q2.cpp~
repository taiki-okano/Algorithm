#include <iostream>
#include <algorithm>

constexpr int MAX_N = 100;

int main(){
	int in[MAX_N];
	int I, J;
	int sum = 0;

	std::cin >> I;

	for(int i = 0; i < I; ++i){
		std::cin >> J;
		for(int j = 0; j < J; ++j){
			std::cin >> in[j];
		}

		std::nth_element(in, in + (J / 2), in + J);
		sum += in[J / 2];
	}

	std::cout << sum / I << std::endl;

	return 0;
}
