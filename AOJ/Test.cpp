#include <iostream>
#include <string>

std::string compare(std::string s1, std::string s2){
    if(s1.length() == s2.length()){
        for(int i = 0; i < s1.length(); ++i){
            if(s1[i] != s2[i])
                return s1[i] > s2[i] ? s1 : s2;
        }
    }
    else if(s1.length() > s2.length()) return s1;
    return s2;
}

int main(){
	std::string str1, str2, str3;
	str1 = -1;
	str2 = "123123";
	char c = '2';
	str3 = c;
	str3 = -1;
	std::cout << compare(str1, str2) << std::endl << str3 << std::endl;
}
