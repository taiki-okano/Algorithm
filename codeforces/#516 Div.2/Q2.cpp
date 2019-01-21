#include <iostream>

int main(){

	int N;

	std::cin >> N;

	while(N--){

		long long x;

		std::cin >> x;

		long long ans = 1;
		for(int i = 0; i < 30; ++i){
			if((x & (1 << i)) != 0){
				ans *= 2;
			}
		}

		std::cout << ans << std::endl;
	}

	return 0;
}
