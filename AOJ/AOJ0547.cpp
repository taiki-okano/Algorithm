#include <iostream>

const int MAX_WH = 102;

int dp_table[MAX_WH][MAX_WH][2] = {};
int W, H;

//up = 1, right = 0;

int main(){
    for(int i = 0; i < MAX_WH; ++i){
        dp_table[i][1][0] = dp_table[1][i][0] = dp_table[i][1][1] = dp_table[1][i][1] = 1;
    }
    
    for(int i = 2; i < MAX_WH; ++i){
        for(int j = 2; j < MAX_WH; ++j){
            dp_table[i][j][0] = (dp_table[i - 2][j][1] + dp_table[i][j - 1][0]) % 100000;
            dp_table[i][j][1] = (dp_table[i - 1][j][1] + dp_table[i][j - 2][0]) % 100000;
        }
    }


    while(true){
        std::cin >> W >> H;
        if(W == 0 && H == 0)
            break;

        std::cout << (dp_table[W][H - 1][0] + dp_table[W - 1][H][1]) % 100000 << std::endl;
    }
    return 0;
}
