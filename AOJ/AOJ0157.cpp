#include <iostream>
#include <algorithm>

#define MAX_NM 200

struct dp{
	int i;
	std::pair<int, int> doll;
};

int main(){
	std::pair<int, int> dolls[MAX_NM];
	int n, m;

	while(true){
		std::cin >> n;
		if(!n)
			break;
		for(int i = 0; i < n; ++i)
			std::cin >> dolls[i].first >> dolls[i].second;

		std::cin >> m;
		for(int i = 0; i < m; ++i)
			std::cin >> dolls[i].first >> dolls[i].second;

		std::sort(dolls, dolls + (n + m));

		for(int i = 1; i < n + m; ++i){
			for(int j = 0; j < )
		}
	}
	return 0;
}