#include <iostream>
#include <algorithm>

int main(){
	int n, a, b, c, d;

	std::cin >> n >> a >> b >> c >> d;

	int x = n / a, y = 0;
	if(n % a != 0){
		++x;
	}

	int ans = b * x;

	while(x > 0){
		--x;
		y = (n - x * a) / c;
		if((n - x * a) % c != 0){
			++y;
		}

		ans = std::min(ans, b * x + d * y);
	}

	std::cout << ans << std::endl;
}
