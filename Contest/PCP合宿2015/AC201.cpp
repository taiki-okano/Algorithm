#include <iostream>

long factorial(int n){
	long ans = 1;
	for(int i = 1; i < n; ++i)
		ans *= 10;
	return ans;
}

int main(){
	long a, n, ans = 0;
	std::cin >> a >> n;

	int i = 0;
	while(true){
		++i;
	
		ans += a % n * factorial(i);
		a = (a - a % n) / n;
		if(a == 0) break;
	}
	std::cout << ans << std::endl;
	return 0;
}