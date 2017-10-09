#include <iostream>

unsigned long long solve(int h, int w);

unsigned long long factorial(int n);

int main(){
    /*
    std::cout << "factorial(5) : " << factorial(5) << std::endl;
    std::cout << "solve(0, 1) : " << solve(0, 1) << std::endl;
    std::cout << "solve(2, 3) : " << solve(2, 3) << std::endl;
    */
    int H, W, A, B;
    std::cin >> H >> W >> A >> B;
    --H, --W;
    unsigned long long ans = 0;
    int h1 = H - A, w1 = B, h2 = A, w2 = W - B - 1;
    for(; h1 >= 0; --h1, ++h2){
        ans += (solve(h1, w1) * solve(h2, w2)) % 1000000007;
        ans %= 1000000007;
    }
    ans += (solve(H - A, B) * solve(A - 1, W - B)) % 1000000007;
    ans %= 1000000007;
    std::cout << ans << std::endl;
    return 0;
}

unsigned long long solve(int h, int w){
    if(h == 0 || w == 0){
        return 1;
    }
    return factorial(h + w) / (factorial(h) * factorial(w));
}

unsigned long long factorial(int n){
    unsigned long long res = 1;
    for(int i = 2; i <= n; ++i){
        res *= i;
    }
    return res;
}
