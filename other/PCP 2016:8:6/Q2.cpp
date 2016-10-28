#include <cstdio>
#include <algorithm>

constexpr int MAX_N = 10000, MAX_K = 1000;

int main(){
    int n, k, count[MAX_K];
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            int ih, im, oh, om;
            scanf("%d:%d%d:%d", &ih, &im, &oh, &om);
            if(ih == 0){
                continue;
            }
            if((ih >= 10 && ih <= 12) || (ih == 13 && im == 0)){
                if((oh >= 14 && oh <=16) || (oh == 17 && om == 0)){
                    int h = oh - ih, m = om - im;
                    if(h >= 5 || (h == 4 && m >= 0)){
                        ++count[j];
                    }
                }
            }
        }
    }
    for(int i = 0; i < k; ++i){
        printf("%d\n", count[i]);
    }
    return 0;
}