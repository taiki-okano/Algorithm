#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

int count[4];
std::string in;

int main(){
    std::cin >> in;
    for(int i = 0; i < in.size(); ++i){
        char c = in[i];
        switch (c) {
            case 'K':
                ++count[0];
                break;
            case 'U':
                ++count[1];
                break;
            case 'P':
                ++count[2];
                break;
            case 'C':
                ++count[3];
                break;
       }
    }
    
    int ans = 0;
    while (true) {
        bool flag1 = false, flag2 = false;
        for(int i = 0; i < 4; ++i){
            if(count[i] == 0){
                flag1 = true;
                break;
            }
            --count[i];
        }
        if(!flag1)
            ++ans;
        else
            break;
    }
    
    std::cout << ans << std::endl;

    return 0;
}
