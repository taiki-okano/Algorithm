#include <iostream>

int main(){
	int in[5];
	for(auto &x : in){
		std::cin >> x;
	}
	for(auto &x : in){
		if(x >= 480){
			std::cout << "Rank A\n";
		}
		else if(x >= 200){
			std::cout << "Rank B\n";
		}
		else{
			std::cout << "Rank C\n";
		}
	}
	return 0;
}
