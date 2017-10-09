#include <cstdio>
#include <algorithm>

constexpr int MAX_NX = 1000;

int main(){
    int N, x[MAX_NX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &x[i]);
    }
    while(true){
        int min = MAX_NX;
        bool flag = false;
        for(int i = 0; i < N; ++i){
            if(x[i] > 0){
                min = std::min(x[i], min);
            }
        }
        for(int i = 0; i < N; ++i){
            x[i] -= min;
            if(x[i] > 0){
                if(flag){
                    printf(" ");
                }
                else{
                    flag = true;
                }
                printf("%d", x[i]);
            }
        }
        if(flag){
            printf("\n");
        }
        else{
            break;
        }
    }
    return 0;
}