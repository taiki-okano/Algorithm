#include <iostream>
#include <limits>
#include <cstring>
#include <cmath>

constexpr int MAX = 200;
constexpr int MAX_C = 100;

int D, N, T[MAX], A[MAX], B[MAX], C[MAX];
int memo[MAX_C + 1][MAX + 1];

int solve(int tmp, int n = 1);

int main(){
	std::ios::sync_with_stdio(false);
	
	memset(memo, -1, sizeof(memo));

	std::cin >> D >> N;

	for(int i = 0; i < D; ++i){
		std::cin >> T[i];
	}

	for(int i = 0; i < N; ++i){
		std::cin >> A[i] >> B[i] >> C[i];
	}

	int ans = 0;
	for(int i = 0; i < N; ++i){
		if(A[i] <= T[0] && T[0] <= B[i]){
			ans = std::max(ans, solve(C[i]));
		}
	}

	std::cout << ans << std::endl;
	return 0;
}

int solve(int tmp, int n){
	if(n == D){
		return 0;
	}
	if(memo[tmp][n] != -1){
		return memo[tmp][n];
	}

	int res = 0;
	for(int i = 0; i < N; ++i){
		if(A[i] <= T[n] && T[n] <= B[i]){
			res = std::max(res, solve(C[i], n + 1) + abs(tmp - C[i]));
		}
	}
	//std::cout << "memo[" << tmp << "][" << n << "] = " << res << std::endl;
	return memo[tmp][n] = res;
}
