#include <iostream>
#include <string>
#include <algorithm>

#define MAX 15

int n;
std::string str[MAX];

int main(){
	std::cin >> n;
	
	int max = 0;
	for(int i = 0; i < n; ++i){
		std::cin >> str[i];
		max = max > str[i].size() ? max : str[i].size();
	}

	for(int i = 0; i < n + 2; ++i){
		if(i == 0 || i == n + 1){
			for(int j = 0; j < max + 4; ++j){
				if(j == 0 || j == max + 3)
					std::cout << "+";
				else
					std::cout << "-";
			}
		}
		else{
			for(int j = 0; j < max + 4; ++j){
				if(j == 1 || j == max + 2)
					std::cout << " ";
				else if(j == 0 || j == max + 3)
					std::cout << "|";
				else if(str[i - 1].size() + 1 > j - 1)
					std::cout << str[i - 1][j - 2];
				else
					std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	return 0;
}