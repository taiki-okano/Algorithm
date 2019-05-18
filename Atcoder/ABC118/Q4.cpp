#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

constexpr int matches[] = {2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){

	int N, M;

	std::cin >> N >> M;

	std::vector<int> A;

	int min_match = 8;
	int max_number = 0;
	for(int i = 0; i < M; ++i){
		int input;
		std::cin >> input;
		A.push_back(input);

		if(min_match > matches[input - 1]){
			min_match = matches[input - 1];
			max_number = input;
		}
	}

	std::string ans;

	for(int i = 0; i < N / min_match; ++i){
		ans += char('0' + max_number);
	}

	std::vector<std::pair<int, int>> upper_numbers; //(number, match)
	std::vector<std::pair<int, int>> lower_numbers; //(match, number)

	for(auto& x : A){
		if(x > max_number){
			upper_numbers.push_back(std::pair<int, int>(x, matches[x - 1] - min_match));

		}
		else if(x < max_number){
			lower_numbers.push_back(std::pair<int, int>(matches[x - 1] - min_match, x));
		}
	}

	int surplus = N % min_match;

	std::sort(upper_numbers.begin(), upper_numbers.end());
	std::sort(lower_numbers.begin(), lower_numbers.end(), std::greater<std::pair<int, int>>());

	int index = 0;
	for(int i = 0; i < upper_numbers.size(); ++i){
		while(surplus >= upper_numbers[i].second){
			ans[index] = char('0' + upper_numbers[i].first);
			surplus -= upper_numbers[i].second;
			++index;
		}
	}

	index = ans.size() - 1;
	for(int i = 0; i < lower_numbers.size(); ++i){
		while(surplus >= lower_numbers[i].first){
			ans[index] = char('0' + lower_numbers[i].second);
			surplus -= lower_numbers[i].first;
			--index;
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
