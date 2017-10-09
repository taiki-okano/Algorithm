#include <iostream>
#include <string>

std::string str;

bool find(const std::string& str, const std::string& key){
	for(int i = 0; i < str.size() - key.size() + 1; ++i){
		bool flag = true;
		for(int j = 0, k = i; j < key.size(); ++j, ++k){
			if(str[k] != key[j]){
				flag = false;
				break;
			}
		}
		if(flag)
			return true;
	}

	return false;
}

int main(){
	std::cin>>str;
	if(find(str, "ZERO"))
		std::cout<<1<<std::endl;
	else if(find(str, "ONE"))
		std::cout<<2<<std::endl;
	else if(find(str, "TWO"))
		std::cout<<3<<std::endl;
	else if(find(str, "THREE"))
		std::cout<<4<<std::endl;
	else if(find(str, "FOUR"))
		std::cout << 5 << std::endl;
	else
		std::cout<<"NO NUMBER"<<std::endl;
	return 0;
}