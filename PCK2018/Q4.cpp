#include <iostream>

int main(){

	int A, B, X;

	std::cin >> A >> B >> X;

	if(A >= B * 2){
		if(X % 500 == 0){
			std::cout << X / 500 * B << std::endl;
		}
		else{
			std::cout << (X / 500 + 1) * B << std::endl;
		}
	}
	else{
		if(X % 1000 == 0){
			std::cout << X / 1000 * A << std::endl;
		}
		else if(X % 1000 <= 500){
			if(A > B){
				std::cout << X / 1000 * A + B << std::endl;
			}
			else{
				std::cout << (X / 1000 + 1) * A << std::endl;
			}
		}
		else{
			std::cout << (X / 1000 + 1) * A << std::endl;
		}
	}

	return 0;
}
