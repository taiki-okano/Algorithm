#include <cstdio>
#include <cmath>
#include <algorithm>

int main(){

    int N, K;

    scanf("%d%d", &N, &K);

    int sum = 0;
    for(int i = 0; i < N; ++i){

        int x;

        scanf("%d", &x);

        int tmp;

        if(K - x > 0){
            tmp = K - x;
        }
        else{
            tmp = x - K;
        }

        sum += std::min(x, tmp) * 2;
    }

    printf("%d\n", sum);

    return 0;
}
