#include <iostream>
#include <algorithm>
#include <vector>

constexpr int MAX_N = 100001, MAX_Q = 1001;
constexpr long long MAX_T = 1000000000000000001;
constexpr long long INF = 1000000000000000001;

int n, q, d[MAX_N];
long long t, a[MAX_N];

std::vector<long long> p;

int main(){
    std::cin >> n >> t >> q;

    int tmp = -1;
    for(int i = 0; i < n; ++i){
        std::cin >> a[i] >> d[i];
        if(d[i] == 2) d[i] = -1;

        if(tmp > d[i] && std::abs(a[i] - a[i - 1]) / 2 < t) p.push_back((a[i] + a[i - 1]) / 2);
        
        tmp = d[i];
    }

    for(int i = 0; i < q; ++i){
        int index;
        std::cin >> index;
        --index;

        long long res = t * d[index] + a[index];
        
        long long l, s;
        if(d[index] == -1) s = t * d[index] + a[index], l = a[index];
        else s = a[index], l = t * d[index] + a[index];
        
        for(auto &x : p){
            if(std::abs(a[index] - x) / 2 <= t && x >= s && x <= l && std::abs(a[index] - x) < std::abs(a[index] - res))
               res = x;
        }

        std::cout << res << std::endl;
    }

    return 0;
}
