#include <iostream>
#include <vector>
#include <algorithm>

int main(){

	int N, M;

	std::vector<int> A;

	std::cin >> N >> M;

	for(int i = 0; i < N; ++i){

		int input;

		std::cin >> input;

		A.push_back(input);
	}

	std::sort(A.begin(), A.end());

	int sum = 0;

	for(int i = 0, j = N - 1; i < j && M > 0; ++i, --j, --M){
		sum += A[j] - A[i];
	}

	std::cout << sum << std::endl;

	return 0;
}
