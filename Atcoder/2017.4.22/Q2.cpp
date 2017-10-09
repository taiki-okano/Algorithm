#include <iostream>
#include <string>

int main(){
	std::string a, b;
	std::cin >> a >> b;
	if(a.length() < b.length()){
		std::cout << "LESS" << std::endl;
	}
	else if(a.length() > b.length()){
		std::cout << "GREATER" << std::endl;
	}
	else if(a > b){
		std::cout << "GREATER" << std::endl;
	}
	else if(a < b){
		std::cout << "LESS" << std::endl;
	}
	else{
		std::cout << "EQUAL" << std::endl;
	}
	return 0;
}
