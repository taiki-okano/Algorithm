#include <iostream>
#include <cstdio>

double a, b, c, d, e, f, x, y;

int main(){
	std::cin >> a >> b >> c >> d >> e >> f;
	x = (c * e - b * f) / (a * e - b * d);
	y = (c - a * x) / b;
	
	printf("%.3f %.3f", x, y);
	std::cout << std::endl;
	return 0;
}