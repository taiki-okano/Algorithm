#include <iostream>

int main(){
    int N;
    std::cin >> N;

    int a_score = 0, b_score = 0;
    while(N--){
        int a, b;
        std::cin >> a >> b;
        if(a > b) ++a_score;
        else if(a < b) ++b_score;
    }
    std::cout << a_score << " " << b_score << std::endl;

    return 0;
}
