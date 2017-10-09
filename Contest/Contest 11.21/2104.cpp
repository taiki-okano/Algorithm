#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <functional>

const int MAX = 100000;
int t, n, k;
int x[MAX];

int main(){
    std::cin >> t;
    for(int a = 0; a < t; ++a){
        std::cin >> n >> k;
        std::vector<int> sub;
        int s, g;
        int in1, in2;
        for(int i = 0; i < n; ++i){
            std::cin >> in1;
            if(i == 0)
                s = in2 = in1;
            if(i == n - 1)
                g = in1;
            sub.push_back(in1 - in2);
            in2 = in1;
        }
        std::sort(sub.begin(), sub.end(), std::greater<int>());
        int l = g - s;
        // std::cout << "l : " << l << std::endl;
        // std::cout << "s : " << s << std::endl;
        // std::cout << "g : " << g << std::endl;
        for(int i = 0; i < k - 1; ++i){
            if(i == n - 1)
                break;
            // std::cout << "sub i : " << sub[i] << std::endl;
            l -= sub[i];
        }
        std::cout << l << std::endl;
    }
    return 0;
}
