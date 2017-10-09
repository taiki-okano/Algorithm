#include <iostream>
#include <string>


int main(){
	int n = 0;

	std::cin >> n;
	while(n--){
		std::string str, ans = "";
		std::cin >> str;
		for(int i = 0; i < str.size(); ++i){
			if(str[i] == '@'){
				for(int j = 0; j < str[i + 1] - '0'; ++j)
					ans += str[i + 2];
				i += 2;
			}
			else
				ans += str[i];
		}
		std::cout << ans << std::endl;
	}
	return 0;
}