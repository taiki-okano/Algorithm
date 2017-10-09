#include <iostream>

int main(){
	int h, w;
	std::cin >> h >> w;
	std::cout << (h - 1) * w + h * (w - 1) << std::endl;
	return 0;
}