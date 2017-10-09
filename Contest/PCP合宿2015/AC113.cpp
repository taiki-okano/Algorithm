#include <iostream>
#include <string>

int main(){
	std::string str;
	std::cin >> str;
	for(int i = 0; i < str.size(); ++i){
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += ('a' - 'A');
		else
			str[i] -= ('a' - 'A');	
	}
	std::cout << str << std::endl;
	return 0;
}