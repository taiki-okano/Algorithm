#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

const int MAX_N = 300000;

typedef std::pair<int, int> Pair;

int N;

std::vector<Pair> c;
int count[MAX_N];

int main(){

    std::cin >> N;

    for(int i = 0; i < N; ++i){

		int M;

		std::cin >> M;

		for(int j = 0; j < M; ++j){

			int input;

			std::cin >> input;

			c.push_back(Pair(input, i));
		}
    }

	std::sort(c.begin(), c.end(), std::greater<Pair>());

	long long ans = 0;

	int count2 = 0;
	for(int i = 0; i < c.size(); ++i){
		if(count[c[i].second] <= c[i].second){
			for(int j = 0; j <= c[i].second; ++j){
				count[j]++;
			}
			ans += c[i].first;
			++count2;
			if(count2 == N){
				break;
			}
		}
	}

	std::cout << ans << std::endl;

    return 0;
}
