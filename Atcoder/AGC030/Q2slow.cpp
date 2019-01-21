#include <iostream>
#include <algorithm>
#include <cmath>

constexpr int MAX_N = 200000;

int L, N;
int X[MAX_N];

int dfs(int max_index, int min_index = 0, int pos = 0);

int main(){

	std::cin >> L >> N;

	for(int i = 0; i < N; ++i){
		std::cin >> X[i];
	}

	std::cout << dfs(N - 1) << std::endl;

	return 0;
}

int dfs(int max_index, int min_index, int pos){

	if(max_index == min_index){
		if(pos > X[max_index]){
			return std::max(pos - X[max_index], (L - pos) + X[max_index]);
		}
		else{
			return std::max(X[max_index] - pos, (L - X[max_index]) + pos);
		}
	}

	int res = 0;

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

	return res;
}

