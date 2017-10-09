#include <cstdio>

constexpr int MAX_N = 50, MAX_X = 500;

int main(){
    int n, tmp;
    bool cards[MAX_X + 1];
    scanf("%d", &n);
    for(int i = 0; i <= MAX_X; ++i){
        cards[i] = false;
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &tmp);
        cards[tmp] = true;
    }
    int count = 0;
    for(int i = 0; i <= MAX_X; ++i){
        if(cards[i] && cards[i + 1]){
            cards[i] = false;
            cards[i + 1] = false;
            ++count;
        }
        if(cards[i]){
            cards[i] = false;
            ++count;
        }
    }
    printf("%d\n", count);
    return 0;
}