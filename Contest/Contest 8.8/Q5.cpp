#include <iostream>
#include <algorithm>
#include <vector>

constexpr int MAX_N = 1000;
constexpr int MAX_K = 1000000;

int main(){
	int N, K;
	std::vector<int> w;

	std::cin >> N >> K;

	for(int i = 0; i < N; ++i){
		int input;
		std::cin >> input;
		w.push_back(input);
	}

	int count = 0;
	while(true){
		auto max = std::max_element(w.begin(), w.end());

		if(*max <= 0){
			break;
		}

		*max -= (K - 1);

		for(auto& x : w){
			--x;
		}

		++count;
	}

	std::cout << count << std::endl;

	return 0;
}
