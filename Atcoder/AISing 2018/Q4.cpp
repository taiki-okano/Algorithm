#include <iostream>

constexpr int MAX_NQ = 100000;

int N, Q;
int A[MAX_NQ];

int main(){

	std::cin >> N;

	int csum[MAX_NQ] = {};

	for(int i = 0; i < N; ++i){
		std::cin >> A[i];

		if(i > 0){
			csum[i] = A[i] + csum[i - 1];
		}
		else{
			csum[i] = A[i];
		}
	}

	for(int i = 0; i < Q; ++i){
		
	}

	return 0;
}
