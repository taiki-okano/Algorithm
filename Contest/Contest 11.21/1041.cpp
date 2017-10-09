#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

int n;

int main(){
    while (true) {
        int ans = 0;
        std::cin >> n;
        if(n == 0)
            break;
        n /= 4;

        for(int i = 0; i < n; ++i){
            int in;
            std::cin >> in;
            ans += in;
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
