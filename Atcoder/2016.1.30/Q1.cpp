#include <iostream>
#include <string>

std::string str = "DiscoPresentsDiscoveryChannelProgrammingContest2016";

int main(){
    int w;
    std::cin >> w;

    int n = 0;

    for(int i = 0; i < 51; ++i){
        ++n;
        std::cout << str[i];
        if(n == w) {
            std::cout << std::endl;
            n = 0;
        }
    }
    if(n != 0)
        std::cout << std::endl;
}
