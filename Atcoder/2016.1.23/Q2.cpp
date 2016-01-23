#include <iostream>

int main(){
    int n;
    std::cin >> n;
    

    int output, input, pnum;
    std::cin >> pnum;
    output = pnum;

    for(int i = 0; i < n - 2; ++i){
        std::cout << output << " ";
        std::cin >> input;
        if(input > pnum) output = pnum;
        else output = input;
        pnum = input;
    }
    
    std::cout << output << " ";
    std::cout << input << std::endl;

    return 0;
}
