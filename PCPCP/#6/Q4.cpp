#include <iostream>
#include <algorithm>
#include <queue>

constexpr int MAX_N = 100000;

using Pair = std::pair<long, int>;

int N;

int main(){

	std::vector<Pair> monsters;

	std::cin >> N;

	for(int i = 0; i < N; ++i){

		int input;

		std::cin >> input;

		monsters.emplace_back(Pair(input, i + 1));
	}

	std::sort(monsters.begin(), monsters.end());

	int count = monsters.size();

	while(count--){

		if((count + 1) % 2 == 1){

			std::cout << monsters[0].second;

			monsters.erase(monsters.begin());
		}
		else{

			auto last = monsters.end();

			if(last == monsters.begin()){
				std::cout << last->second;
			}

			if(last != monsters.begin() && last->first == (last - 1)->first){
				last
			}

		}

		if(count > 0){
			std::cout << ' ';
		}
		else{
			std::cout << std::endl;
		}

	}

	return 0;
}
