#include <cstdio>
#include <algorithm>

constexpr int MAX_N = 100000;

int main(){
    int n, ans;
    double a, b, k;
    scanf("%d%lf%lf%lf", &n, &k, &a, &b);
    
    int min = b, max_profit = 0;;
    for(int i = 0; i < n; ++i){
        int tmp = b;
        b = b * k + a * (1 - k);
        a = tmp;
        min = std::min(min, (int)b);
        int profit = b - min;
        if(profit > max_profit){
            max_profit = profit;
            ans = b;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}