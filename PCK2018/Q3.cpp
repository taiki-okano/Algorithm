#include <iostream>

int main(){

	int N, C;

	std::cin >> N >> C;

	int sum = 0;

	for(int i = 0; i < C; ++i){

		int input;

		std::cin >> input;

		sum += input;
	}

	if(sum % (N + 1) != 0){
		std::cout << sum / (N + 1) + 1 << std::endl;
	}
	else{
		std::cout << sum / (N + 1) << std::endl;
	}

	return 0;
}
