#include <iostream>
#include <vector>

int main(){
	int N, M;

	std::cin >> N >> M;

	std::vector<int> array;

	for(int i = 0; i < N; ++i){
		int input;
		std::cin >> input;
		array.push_back(input);
	}

	for(int i = 0; i < M; ++i){
		int input;
		std::cin >> input;
		std::cout << std::distance(
				array.begin()
				, std::lower_bound(array.begin(), array.end(), input)) + 1 << std::endl;
	}

	return 0;
}
