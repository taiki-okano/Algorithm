#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int N, M;
    std::vector<int> d, t;

    std::cin >> N;
    for(int i = 0; i < N; ++i){
        int input;
        std::cin >> input;
        d.push_back(input);
    }

    std::cin >> M;
    for(int i = 0; i < M; ++i){
        int input;
        std::cin >> input;
        t.push_back(input);
    }

    std::sort(d.begin(), d.end());
    std::sort(t.begin(), t.end());

    int di = 0, ti = 0;
    while(true){
        if(ti >= t.size()){
             std::cout << "YES" << std::endl;
             break;
        }

        if(t[ti] < d[di]){
            std::cout << "NO" << std::endl;
            break;
        }

        if(d[di] == t[ti]){
            ++di, ++ti;
        }
        else {
            ++di;
        }
    }

    return 0;
}
