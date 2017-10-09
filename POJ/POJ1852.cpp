#include <iostream>
#include <algorithm>

#define MAX 1000000

int main(){
    int N, L, n, x[MAX];
    std::cin >> N;
    
    while(N--){
        std::cin >> L >> n;
        for(int i = 0; i < n; ++i){
            std::cin >> x[i];
        }
        
        int max = 0, min = 0;
        for(int i = 0; i < n; ++i){
            max = std::max(max, std::max(L - x[i], x[i]));
            min = std::max(min, std::min(L - x[i], x[i]));
        }
        std::cout << min << ' ' << max << std::endl;
    }
    
    return 0;
}
