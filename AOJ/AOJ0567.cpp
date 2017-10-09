#include <iostream>
#include <algorithm>
 
#define MAX_N 101
 
int N, A, B, C[MAX_N], cal[MAX_N], all = 0;
 
int main(){
    int in;
    std::cin >> N >> A >> B >> in;
     
    for(int i = 0; i < N; ++i)
        std::cin >> cal[i];
         
    std::sort(cal, cal + N, std::greater<int>());
     
    all = in;
    int ans = all / A;
    all += cal[0];
    for(int i = 0; i < N; ++i){
        ans = std::max(ans, all / (A + B * (i + 1)));
        all += cal[i + 1];
    }
    std::cout << ans << std::endl;
    return 0;
}