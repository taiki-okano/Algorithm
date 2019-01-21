#include <iostream>
#include <algorithm>

long long gcd(long long a, long long b){
	if(a == 0) return b;
	else return gcd(b % a, a);
}

int main(){

	long long a, b, x, y;

	std::cin >> a >> b >> x >> y;

	int g = gcd(x, y);
	x /= g;
	y /= g;

	std::cout << std::min(a / x, b / y) << std::endl;

	return 0;
}
