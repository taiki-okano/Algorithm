#include <iostream>

int main(){
	int n, m;
	std::cin >> n >> m;

	m *= 10;
	m -= 5;

	if(m == 5)
		m -= 5;

	double hoge = m * 2 - n - 0.5;

	if((int)hoge > 100)
		std::cout << "Mission:Impossible";
	
	else if((int)hoge < 0)
		std::cout << 0;
	
	else
		std::cout << (int)hoge;

	std::cout << std::endl;

	return 0;
}