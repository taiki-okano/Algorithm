#include <cstdio>
#include <algorithm>

constexpr int MAX_NMAB = 100000;

int N, M, A[MAX_NMAB + 1], B[MAX_NMAB + 1];

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; ++i){
        int input;
        scanf("%d", &input);
        ++A[input];
    }
    for(int i = 0; i < M; ++i){
        scanf("%d", &B[i]);
    }
    bool flag;
    std::sort(B, B + M);
    for(int i = 0; i < M; ++i){
        flag = false;
        for(int j = B[i]; j <= MAX_NMAB; ++j){
            if(A[j] > 0){
                --A[j];
                flag = true;
                break;
            }
        }
        if(!flag){
            puts("NO");
            break;
        }
    }
    if(flag){
        puts("YES");
    }
    return 0;
}