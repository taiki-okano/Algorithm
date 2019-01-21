#include <iostream>
#include <string>

int main(){

	std::string str;

	std::cin >> str;

	bool used[52] = {};

	for(auto& c : str){
		if(c >= 'A' && c <= 'Z') used[int(c - 'A')] = true;
		else used[int(c - 'a') + 26] = true;
	}

	int count = 0;

	for(int i = 0; i < 52; ++i){
		if(used[i]) ++count;
	}

	if(str.length() == 8 && count == 5) std::cout << "Nya" << std::endl;
	else std::cout << "Nyo" << std::endl;

	return 0;
}

// WAはつらたん
