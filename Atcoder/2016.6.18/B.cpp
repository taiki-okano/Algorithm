#include <iostream>
#include <limits>
#include <cmath>

int main(){
    int n;
    std::cin >> n;

    int square_root = sqrt(n);

    int lost = std::numeric_limits<int>::max();

    for(int i = 1; i <= square_root + 1; ++i){
        for(int j = 1; i * j <= n; ++j){
            lost = std::min(lost, abs(i - j) + (n - (i * j)));
        }
    }

    std::cout << lost << std::endl;

    return 0;
}
