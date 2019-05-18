#include <iostream>
#include <vector>
#include <algorithm>

constexpr int MAX_N = 200000;

int N;
std::vector<int> edge[MAX_N];

int dfs(int n, int prev);

int main(){

	std::cin >> N;

	for(int i = 0; i < N - 1; ++i){
		int a, b;

		std::cin >> a >> b;

		--a, --b;

		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	int max = 0, second_max = 0;

	for(auto &x : edge[0]){
		int tmp = dfs(x, 0);
		if(max <= tmp){
			second_max = max;
			max = tmp;
		}
		else if(second_max < tmp){
			second_max = tmp;
		}
	}

	if((max + second_max + 1) <= 3){
		std::cout << "First" << std::endl;
	}
	else if((max + second_max + 1) % 3 <= 1){
		std::cout << "First" << std::endl;
	}
	else{
		std::cout << "Second" << std::endl;
	}

	return 0;
}

int dfs(int n, int prev){

	int res = 0;

	for(auto &x : edge[n]){
		if(x != prev){
			res = std::max(res, dfs(x, n));
		}
	}

	return res + 1;
}
