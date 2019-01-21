#include <iostream>

int main(){

	int N;

	std::cin >> N;

	if((N + 1002) % 3 == 1) std::cout << "Nya" << std::endl;
	else std::cout << "Nyo" << std::endl;

	return 0;
}
