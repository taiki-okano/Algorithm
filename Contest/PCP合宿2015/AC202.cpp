#include <iostream>

#define MAX_N 15

int main(){
	int n, in[MAX_N], rank;
	std::cin >> n;
	for(int i = 0; i < n; ++i)
		std::cin >> in[i];
	std::cin >> rank;
	if(in[rank - 1] == 1)
		std::cout << in[rank - 1] << "pt" << std::endl;
	else
		std::cout << in[rank - 1] << "pts" << std::endl;
	return 0;
}