#include <iostream>
#include <algorithm>
#include <cmath>

constexpr int MAX_N = 200000;

int L, N;
long long X[MAX_N];

long long dp[MAX_N] = {};

int main(){

	std::cin >> L >> N;

	for(int i = 0; i < N; ++i){
		std::cin >> X[i];
	}

	std::cout << dfs(N - 1) << std::endl;

	return 0;
}

long long dfs(int max_index, int min_index, long long pos){

	if(max_index == min_index){
		if(pos > X[max_index]){
			return std::max(pos - X[max_index], (L - pos) + X[max_index]);
		}
		else{
			return std::max(X[max_index] - pos, (L - X[max_index]) + pos);
		}
	}

	int tmp = (pos > X[max_index]) ? 1 : 0;

	if(table[max_index][min_index][tmp] != 0){
		return table[max_index][min_index][tmp];
	}

	long long res = 0;

	//Choose max
	if(pos > X[max_index]){
		res = dfs(max_index - 1, min_index, X[max_index]) + pos - X[max_index];
	}
	else{
		res = dfs(max_index - 1, min_index, X[max_index]) + pos + L - X[max_index];
	}

	//Choose min
	if(pos < X[min_index]){
		res = std::max(res, dfs(max_index, min_index + 1, X[min_index]) + X[min_index] - pos);
	}
	else{
		res = std::max(res, dfs(max_index, min_index + 1, X[min_index]) + X[min_index] + L - pos);
	}

	return table[max_index][min_index][tmp] = res;
}
