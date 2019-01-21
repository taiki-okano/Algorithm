#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdlib>

constexpr int INF = std::numeric_limits<int>::max();
constexpr int LL_INF = std::numeric_limits<long long>::max();

constexpr int MAX_N = 100000;

using Pair = std::pair<int, int>;

std::map<int, int> zip;
int unzip[MAX_N];

void compress(std::vector<int> &x){
	std::sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	for(int i = 0; i < x.size(); ++i){
		zip[x[i]] = i;
		unzip[i] = x[i];
	}
}

int main(){

	int N;
	int A[MAX_N];
	std::vector<int> A_vec;
	int dp[MAX_N] = {};

	std::cin >> N;

	for(int i = 0; i < N; ++i){
		std::cin >> A[i];
		A_vec.push_back(A[i]);
	}

	compress(A_vec);

	for(int i = 0; i < N; ++i){
		A[i] = zip[A[i]];
	}

	for(int i = 0; i < N; ++i){
		if(i == 0 && unzip[A[i]] != 0){
			for(int j = 0; j <= A[i]; ++j){
				++dp[j];
			}
		}
		else if(i > 0 && A[i - 1] < A[i]){
			for(int j = A[i - 1] + 1; j <= A[i]; ++j){
				++dp[j];
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < N; ++i){
		ans = std::max(ans, dp[i]);
	}

	std::cout << ans << std::endl;

	return 0;
}
