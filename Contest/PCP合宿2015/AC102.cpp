#include <iostream>
#include <string>

int main(){
	int n;
	std::string str;
	std::cin >> n;
	for(int i = 0; i < n; ++i)
		std::cin >> str;
	str[0] += ('A' - 'a');
	if(n == 1)
		std::cout << str << " appeared!" << std::endl;
	else
		std::cout << "Monsters appeared!" << std::endl;
	return 0;
}