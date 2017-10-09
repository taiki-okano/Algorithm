#include <iostream>
#include <vector>

#define MAX_NM 32

int main(){
	int triangle[2][MAX_NM], n, m;
	std::cin >> n >> m;

	n++, m--;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i + 1; ++j){
			if(j == 0 || j == i)
				triangle[i % 2][j] = 1;
			else{
				triangle[i % 2][j] = triangle[i % 2 == 0 ? i % 2 + 1 : i % 2 - 1][j - 1] + triangle[i % 2 == 0 ? i % 2 + 1 : i % 2 - 1][j];
			}
		}
	}

	std::cout << triangle[n % 2][m] << std::endl;
	return 0;
}