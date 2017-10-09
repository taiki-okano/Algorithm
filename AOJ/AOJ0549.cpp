#include <iostream>

#define MAX_NM 100000

int main(){
	int n, m, s[MAX_NM + 1], ans = 0;
	std::cin >> n >> m;

	s[0] = 0;

	for(int i = 1; i < n; ++i){
		int in;
		std::cin >> in;
		s[i] = s[i - 1] + in;
	}

	int loc = 0;
	for(int i = 0; i < m; ++i){
		int in;
		std::cin >> in;
		loc += in;
		ans += s[loc + in] - s[loc];
	}

	std::cout << ans % 100000 << std::endl;

	return 0;
}