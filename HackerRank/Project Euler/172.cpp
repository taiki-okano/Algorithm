#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using ull = unsigned long long;

constexpr int MAX_MT = 10000;
constexpr ull MOD = 1000000007;

int M, T;

ull pow(int a, int b){
	if(b == 0){
		return 1;
	}

    return (pow(a, b - 1) * a) % MOD;
}

int main() {
    scanf("%d%d", &M, &T);
    
    for(int i = 0; i < T; ++i){
        int k;
        scanf("%d", &k);
        printf("%llu\n", 9 * pow(10, k - 1) % MOD - (k - M > 0 ? pow(9, k - M) : 0));
    }
    return 0;
}
