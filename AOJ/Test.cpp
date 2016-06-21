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

    std::cout << (-2) % 2 << std::endl;
}
