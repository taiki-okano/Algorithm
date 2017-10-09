#include <iostream>

int main(){

    char input[4];

    std::cin >> input;

    if(input[0] != input[1]){
        puts("No");
    }
    else if(input[1] == input[2]){
        puts("No");
    }
    else if(input[2] != input[3]){
        puts("No");
    }
    else{
        puts("Yes");
    }

    return 0;
}
