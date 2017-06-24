#include <iostream>
#include <vector>

constexpr int MAX_N = 100000, MAX_Q = 1000;
long long a[MAX_N], n, t, q; //初期値, n, t, q
int d[MAX_N]; //方向
std::vector<long long> sp;

int main(){
    std::cin >> n >> t >> q;
    int tmp = 3;
    for(int i = 0; i < n; ++i){
        std::cin >> a[i] >> d[i];
        if(d[i] == 1) d[i] = 1;
        else d[i] = -1;
        if(i != 0 && tmp > d[i] && std::abs(a[i] - a[i - 1]) <= t) sp.push_back((a[i] + a[i - 1]) / 2);
        tmp = d[i];
    }
    for(int i = 0; i < q; ++i){
        int p;
        std::cin >> p;
        --p;
        bool flag = false;
        long long res = 9223372036854775807;
        for(auto x : sp){
            long long l, s;
            l = std::max(a[p] + t * d[p], a[p]), s = std::min(a[p] + t * d[p], a[p]);
            if(x >= s && x <= l && x - a[p] < res) {
                flag = true;
                res = x;
            }
        }
        if(!flag) std::cout << a[p] + t * d[p] << std::endl;
        else std::cout << res << std::endl;
    }
    return 0;
}
