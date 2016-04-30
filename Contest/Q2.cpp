#include <iostream>

int main(){
    int right = 0, left = 0;
    int n;
    std::cin >> n;

    while(n--){
        char in;
        std::cin >> in;
        if('(' == in){
            int num;
            std::cin >> num;
            //if(right == 0) left += num;
            //else if(right < num){
              //  num -= right;
                //right = 0;
                //left += num;
            //}
            //else right -= num;
            left += num;
        }
        
        if(')' == in){
            int num;
            std::cin >> num;
            if(left == 0) right += num;
            else if(left < num){
                num -= left;
                left = 0;
                right += num;
            }
            else left -= num;
        }
    }
    
    if(right == 0 && left == 0) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;

    return 0;
}
