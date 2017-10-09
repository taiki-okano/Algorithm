#include <iostream>
#include <string>

int main(){
	for(int i = 0; i < 3; ++i){
		std::string str;
		std::cin >> str;
		std::cout << static_cast<char>(str[0] + ('A' - 'a'));
	}
	std::cout << std::endl;
	return 0;
}
