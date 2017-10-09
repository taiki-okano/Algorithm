#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main(){

    using ull = unsigned long long;

    ull N, C;

    std::vector<ull> sticks;

    std::cin >> N >> C;

    for(int i = 0; i < N; ++i){
        ull input;
        std::cin >> input;

        sticks.push_back(input);
    }

    std::sort(sticks.begin(), sticks.end(), std::greater<ull>());

    int ans = N;
    int begin = 0;
    int end = N - 1;
    while(true){
        if(begin >= end){
            break;
        }
        if(sticks[begin] + sticks[end] + 1 <= C){
            --ans;
            --end;
            ++begin;
        }
        else{
            ++begin;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
