#include <iostream>

constexpr int MAX_HW = 200;

int main(){

    int H, W, A, B;

    std::cin >> H >> W >> A >> B;

    char field[MAX_HW][MAX_HW];
    int a[MAX_HW][MAX_HW] = {};
    int b[MAX_HW][MAX_HW] = {};

    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            std::cin >> field[i][j];

            if(field[i][j] == 'S'){
                ++a[H - i][j];
                ++a[H - i][W - j];
                ++b[i][W - j];
                ++b[H - i][W - j];
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(a[i][j] > 0 && b[i][j] > 0 && field[i][j] == 'S'){
                ans += A + B;
                --a[H - i][j];
                --a[H - i][W - j];
                --b[i][W - j];
                --b[H - i][W - j];
                field[i][j] = '.';
            }
        }
    }

    if(A > B){
        for(int i = 0; i < H; ++i){
            for(int j = 0; j < W; ++j){
                if(a[i][j] > 0 && field[i][j] == 'S'){
                    ans += A;
                    --a[H - i][j];
                    --a[H - i][W - j];
                    --b[i][W - j];
                    --b[H - i][W - j];
                    field[i][j] = '.';
                }
            }
        }
        for(int i = 0; i < H; ++i){
            for(int j = 0; j < W; ++j){
                if(b[i][j] > 0 && field[i][j] == 'S'){
                    ans += B;
                    --a[H - i][j];
                    --a[H - i][W - j];
                    --b[i][W - j];
                    --b[H - i][W - j];
                    field[i][j] = '.';
                }
            }
        }
    }
    else{
        for(int i = 0; i < H; ++i){
            for(int j = 0; j < W; ++j){
                if(b[i][j] > 0 && field[i][j] == 'S'){
                    ans += B;
                    --a[H - i][j];
                    --a[H - i][W - j];
                    --b[i][W - j];
                    --b[H - i][W - j];
                    field[i][j] = '.';
                }
            }
        }
        for(int i = 0; i < H; ++i){
            for(int j = 0; j < W; ++j){
                if(a[i][j] > 0 && field[i][j] == 'S'){
                    ans += A;
                    --a[H - i][j];
                    --a[H - i][W - j];
                    --b[i][W - j];
                    --b[H - i][W - j];
                    field[i][j] = '.';
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
