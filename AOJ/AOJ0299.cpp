#include <iostream>

#define MAX_N 100000
#define MAX_M 10000

int n, m, count = 0, p;
bool stations[MAX_N] = {false};

int solve(int a, int target[]){

};

int main(){
	std::cin >> n >> m >> p;

	for(int i = 0; i < m; ++i){
		int in;
		std::cin >> in;
		stations[in - 1] = true;
	}

	

	return 0;
}