#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cmath>
#include <cstring>
#include <cstdlib>

constexpr int INF = std::numeric_limits<int>::max();
constexpr int LL_INF = std::numeric_limits<long long>::max();

constexpr int MAX = 2019;

using Pair = std::pair<int, int>;

int main(){

	int N, M;
	int X[MAX + 1];

	std::cin >> N;

	for(int i = 0; i < N; ++i){
		std::cin >> X[i];
	}

	std::cin >> M;

	for(int i = 0; i < M; ++i){

		int input;

		std::cin >> input;
		--input;

		if(X[input] < MAX && X[input + 1] != X[input] + 1){
			++X[input];
		}
	}

	for(int i = 0; i < N; ++i){
		std::cout << X[i] << std::endl;
	}

	return 0;
}
