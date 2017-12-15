#include <iostream>
#include <algorithm>

int main(){
	int N;

	std::cin >> N;

	int ans = 0, tmp = 0;
	for(int i = 0; i < N; ++i){
		int input;
		std::cin >> input;

		if(input == 1){
			++tmp;
		}
		else{
			tmp = 0;
		}

		ans = std::max(ans, tmp);
	}

	std::cout << ans + 1 << std::endl;
}
