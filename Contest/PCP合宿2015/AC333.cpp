#include <iostream>
#include <cstring>

#define MAX_HW 200
#define MAX_N 9
#define MAX_M 50

int w, h, n, m, sx, sy, gx, gy;
int MP[MAX_N][MAX_N]
char field[MAX_HW][MAX_HW];

int bfsToWP();

int main(){
    std::cin >> w >> h >> n >> m;
    
    for(int i = 0; i < w; ++i){
        for(int j = 0; j < h; ++j){
            std::cin >> field[i][j];
            if(field[i][j] == 'S')
                sx = i, sy = j;
            else if(field[i][j] == 'G')
                gx = i, gy = j;
        }
    }

    for(int i = 0; i < m; ++i){
        int in1, in2, in3;
        std::cin >> in1 >> in2 >> in3;

    }
    return 0;
}

int bfsToWP(){

}