#include <iostream>
#include <algorithm>

int main(){
    int a, b, c, d, e, f;

    std::cin >> a >> b >> c >> d >> e >> f;

    int sumA = a + b + c + d - std::min({a, b, c, d}), sumB = std::max(e, f);
    
    std::cout << sumA + sumB << std::endl;

    return 0;
}
