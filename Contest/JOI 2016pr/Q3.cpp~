#include <iostream>
#include <vector>

int main(){
    int N;
    std::vector<int> input;
    std::cin >> N;
    for(int i = 0; i < N; ++i){
        input.push_back(i);
        std::cin >> input[i];
    }

    std::reverse(input.begin(), input.end());

    for(int i = 0; i < N; ++i){
        if(i != 0) std::cout << " ";
        std::cout << input[i];
    }
    std::cout << std::endl;
    return 0;
}
