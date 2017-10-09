#include <iostream>
#include <algorithm>

constexpr int MAX_N = 100;

int main(){
    int array[2 * MAX_N], n;
    std::cin >> n;
    
    for(int i = 0; i < 2 * n; ++i){
        std::cin >> array[i];
    }

    std::sort(array, array + 2 * n);

    int ans = 0;

    for(int i = 0; i < 2 * n; i += 2){
        ans += array[i];
    }
    
    std::cout << ans << std::endl;

    return 0;
}
