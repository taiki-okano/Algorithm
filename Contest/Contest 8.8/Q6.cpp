#include <iostream>
#include <vector>

int main(){
	int N;

	std::cin >> N;

	int amax = 0, bmax = 0;
	for(int i = 0; i < N; ++i){
		int a, b;
		std::cin >> a >> b;
		amax += a, bmax += b;
	}

	std::cout << std::max(amax, bmax) << std::endl;

	return 0;
}
