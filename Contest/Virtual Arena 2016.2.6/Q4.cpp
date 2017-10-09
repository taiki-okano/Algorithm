#include <iostream>
#include <string>
#include <algorithm>

int main(){
    std::string str;
    std::cin >> str;

    int start = 0, last = str.size() - 1;

    int o_score, x_score;
    for(int i = start; i <= last; ++i){
        if(str[i] == 'o'){
            o_score = i;
        }
        str[i] = 'o';
    }
    for(int i = last; last >= start; --i){
        if(str[i] == 'o'){
            o_score = std::max(i, o_score);
        }
        str[i] = 'o';
    }

    for(int i = start; i <= last; ++i){
        if(str[i] == 'x'){
            x_score = i;
        }
    }
    for(int i = last; last >= start; --i){
        if(str[i] == 'x'){
            x_score = std::max(i, x_score);
        }
    }
    
    if(o_score > x_score) std::cout << 'o' << std::endl;
    else std::cout << 'x' << std::endl;

    return 0;
}
