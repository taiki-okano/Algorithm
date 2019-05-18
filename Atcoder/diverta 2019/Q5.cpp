#include <iostream>

constexpr int MAX_N = 50000;
constexpr int MOD = 1e9 + 7;

int N;
int A[MAX_N];
int csum[MAX_N + 1][30];

int main(){

	std::cin >> N;

	for(int i = 0; i < N; ++i){

		std::cin >> A[i];

		for (int j = 0; j < 30; ++j){
		
			if(A[i] & 1 << j){
				csum[i + 1][j] = csum[i][j] + 1;
			}
		}
	}

	return 0;
}
