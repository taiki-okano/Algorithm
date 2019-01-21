#include <iostream>
#include <cmath>

int main(){

	int N, M;
	int x1, y1, x2, y2;

	std::cin >> N >> M;
	std::cin >> x1 >> y1 >> x2 >> y2;

	if(x1 == x2 && y1 == y2){
		if(M == N){
			std::cout << "Yes" << std::endl;
		}
		else{
			std::cout << "No" << std::endl;
		}
		return 0;
	}

	if(M - N >= abs(x1 - x2) + abs(y1 - y2)){
		std::cout << "Yes" << std::endl;
	}
	else{
		std::cout << "No" << std::endl;
	}

	return 0;
}
