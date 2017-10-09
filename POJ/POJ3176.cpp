#include <iostream>
#include <cstring>
#include <algorithm>

const int MAX_N = 351;

int dp_sum[MAX_N][MAX_N];
int score[MAX_N][MAX_N];

int main(){
	int n;
	std::cin >> n;
	
	memset(dp_sum, 0, sizeof(dp_sum));
	
	for(int i = 0; i < n; ++i){
		dp_sum[n][i] = 0;
	}
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= i; ++j){
			std::cin >> score[i][j];
		}
	}
	
	for(int i = n - 1; i >= 0; --i){
		for(int j = 0; j <= i; ++j){
			dp_sum[i][j] = std::max(dp_sum[i + 1][j], dp_sum[i + 1][j + 1]) + score[i][j];	
		}
	}
	
	std::cout << dp_sum[0][0] << std::endl;
	
	return 0;
}