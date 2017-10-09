#include <cstdio>

constexpr long long MOD = 1000000007;
constexpr long long MAX_HW = 100000;

long long abs(long long a);

long long factrial(long long n);

long long function(long long a, long long b);

int main(){
    long long H, W, y, x;
    scanf("%lld%lld%lld%lld", &H, &W, &y, &x);
    printf("%lld\n", (function(y - 1, x - 1) % MOD) * (function(H - y, W - x) % MOD) % MOD);
    return 0;
}

long long function(long long a, long long b){
    return ((factrial(a + b) % MOD) / (((factrial(a) % MOD) * (factrial(b) % MOD)) % MOD)) % MOD;
}

long long factrial(long long n){
    if(n == 1){
        return 1;
    }
    return (n % MOD) * (factrial(n - 1) % MOD) % MOD;
}

long long abs (long long a){
    if(a < 0){
        return -a;
    }
    return a;
}