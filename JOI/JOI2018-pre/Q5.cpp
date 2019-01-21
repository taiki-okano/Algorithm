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

constexpr int MAX_NM = 200000;

using Pair = std::pair<int, int>;

int N, M;
int A[MAX_NM];
std::vector<Pair> R;

int dfs(int iR = 0, int iA = 0);

int main(){

	std::cin >> N >> M;

	for(int i = 0; i < N; ++i){
		std::cin >> A[i];
	}

	for(int i = 0; i < M; ++i){

		int l, r;

		std::cin >> l >> r;

		--l, --r;

		R.push_back(Pair(l, r));
	}

	std::sort(R.begin(), R.end());

	int iR = 0;
	int next = R[0].first;
	int ans = 0;

	for(int i = 0; i < N; ++i){

		if(i < next){
			ans += A[i];
		}
		else{

		}
	}

	std::cout << dfs() << std::endl;

	return 0;
}

int dfs(int iR, int iA){

	if(iA >= N){
		return 0;
	}

	int sum = 0;

	int begin = R[iR].first;
	int end = R[iR].second;

	for(int i = iA; i < begin; ++i){
		if(i == N){
			return 0;
		}
		sum += A[i];
	}

	int next_begin, next_end;
	if(iR < M - 1){
		next_begin = R[iR + 1].first;
		next_end = R[iR + 1].second;
	}
	else{
		next_begin = MAX_NM;
		next_end = MAX_NM;
	}

	if(end >= next_begin){

		int max = 0, index;
		for(int i = iA; i <= end; ++i){
			if(max < A[i]){
				max = A[i];
				index = i;
			}
		}

		if(index < next_begin){
			return sum + std::max(max + dfs(iR + 1, end + 1), dfs(iR + 1, next_begin));
		}
		else{
			return sum + std::max(max + dfs(iR + 2, next_end), dfs(iR + 1, next_begin));
		}
	}
	else{

		int max = 0;
		for(int i = iA; i <= end; ++i){
			max = std::max(max, A[i]);
		}
		return sum + max + dfs(iR + 1, end + 1);
	}
}
