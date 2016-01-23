#include <iostream>

int main(){
    int n, m;

    std::cin >> n >> m;

    int ans = n / m;
    if(n % m != 0) ++ans;

    std::cout << ans << std::endl;

    return 0;
}
