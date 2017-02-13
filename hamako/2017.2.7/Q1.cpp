#include <iostream>
#include <cmath>
#include <string>
#include <limits>

constexpr int MAX_K = 10;
constexpr int MAX_LEN = 3145725;
constexpr int INF = std::numeric_limits<int>::max();

int LevensteinDistance(const std::string& str);

int Pow(const int x, const int y);

int main(){
	std::ios::sync_with_stdio(false);
	int K;
	std::string str, joi;
	std::cin >> K >> str;
	
	for(int i = K - 1; i >= 0; ++i){
		int pow = Pow(4, K);
		for(int j = 0; j < pow; ++j){
			joi += 'J';
		}
		for(int j = 0; j < pow; ++j){
			joi += 'O';
		}
		for(int j = 0; j < pow; ++j){
			joi += 'I';
		}
	}

	int ans = INF;
	for(int i = 0; i < Pow(4, K - 1); ++i){
		int dis = 0;
		for(int j = i + 1, int k = 0; k < Pow(4, K - 1); ++k, ++j, j %= Pow(4, K - 1)){
			if(str[k] != joi[j]){
				++dis;
			}
		}
		ans = std::min(ans, dis);
	}
	
	return 0;
}

int Pow(const int x, const int y){
	int res = 1;
	for(int i = 0; i < x; ++i){
		res *= y;
	}
	return res;
}
