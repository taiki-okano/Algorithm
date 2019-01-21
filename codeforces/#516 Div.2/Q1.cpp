#include <iostream>
#include <algorithm>

int main(){

	int a, b, c;

	std::cin >> a >> b >> c;

	int sum = a + b + c;
	int max = std::max({a, b, c});

	std::cout << std::max(0, max - (sum - max) + 1) << std::endl;

	return 0;
}
