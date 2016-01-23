#include <iostream>
#include <algorithm>

#define MAX_NM 1000

int n, m, ans;
int p[MAX_NM];

void solve();

int main(){
    while(true){
        std::cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        for(int i = 0; i < n; ++i)
            std::cin >> p[i];
        solve();
        std::cout << ans << std::endl;
    }
    return 0;
}

void solve(){
    ans = 0;
    std::sort(p, p + n, std::greater<int>());
    for(int i = 1; i <= n; ++i){
        if(i % m == 0)
            continue;
        ans += p[i - 1];
    }
    return;
}