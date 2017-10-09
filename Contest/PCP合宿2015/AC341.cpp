#include <iostream>

#define MAX_S 1000

bool field[MAX_S][MAX_S] = {false};
int ans = 0;

int main(){
    int m, s;
    std::cin >> s >> m;
    while(m--){
        int x, y, c;
        std::cin >> x >> y >> c;
        
        x--, y--;
        
        for(int i = x + c; i >= x - c; --i){
            for(int j = y + c; j >= y - c; --j){
                if(i >= 0 && i < s && j >= 0 && j < s){
                    if(abs(x - i) + abs(y - j) <= c && !field[i][j]){
                        field[i][j] = true;
                        ++ans;
                    }
                }
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}