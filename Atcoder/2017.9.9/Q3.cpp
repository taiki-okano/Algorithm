#include <iostream>
#include <algorithm>
#include <vector>

int main(){

    int N;
    std::vector<int> nums;

    std::cin >> N;

    for(int i = 0; i < N; ++i){
        int input;
        std::cin >> input;
        nums.push_back(input);
    }

    std::sort(nums.begin(), nums.end());

    int sum = 0, prev = -1;
    for(auto &x : nums){
        if(prev == x){
            --sum;
            prev = -1;
        }
        else{
            ++sum;
            prev = x;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
