#include <iostream>

int main(){
	int a, b, c, d, e;
	std::cin >> a >> b >> c >> d >> e;

	int ans = 0;
	if(a < 0){
		ans += c * (-a);
		ans += d;
		a = 0;
	}

	ans += (b - a) * e;

	std::cout << ans << std::endl;

	return 0;
}
