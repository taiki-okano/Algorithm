#include <iostream>
#include <algorithm>

int main(){
    int a, b, c, d, p, X, Y;
    std::cin >> a >> b >> c >> d >> p;
    X = p * a;
    
    if(p > c)
        Y = b + d * (p - c);
    else
        Y = b;

    std::cout << std::min(X, Y) << std::endl;

    return 0;
}
