#include <iostream>
#include <string>

int main(){
	std::string str;
	std::cin >> str;

	while(true){
		if(str.size() == 1) break;

		std::string tmp = str;
		int sum = 0;
		for(int j = 0; j < tmp.size(); ++j)
			sum += tmp[j] - '0';
		str = sum;
	
	}
	std::cout << str << std::endl;
	return 0;
}