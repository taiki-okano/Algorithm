#include <iostream>
#include <cmath>

int main(){

	int N;

	std::cin >> N;

	int tmp = int(sqrt(float(N)));

	if(tmp * tmp == N){
		std::cout << "like" << std::endl;
	}
	else{
		std::cout << "don't like" << std::endl;
	}

	return 0;
}
