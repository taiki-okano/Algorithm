#include <iostream>
#include <algorithm>

const int MAX_L = 1000009999;
const int MAX_N = 50099;

int L, N, M;
int D[MAX_N];

bool C(int d){
    int last = 0;
    for(int i = 0; i < N - M; ++i){
        int crt = last + 1;
        while(crt < N && D[crt] - D[last] < d) ++crt;
        if(crt == N) return false;
        last = crt;
    }
    return true;
}

int main(){
    std::cin >> L >> N >> M;
    for(int i = 0; i < N; ++i)
        std::cin >> D[i];

    std::sort(D, D + N);

    int lb = 0, ub = L;

    while(ub - lb > 1){
        int mid = (ub + lb) / 2;
        if(C(mid)) lb = mid;
        else ub = mid;
    }
    
    std::cout << lb << std::endl;
/*
    for(int i = 0; i < 15; ++i){
        std::cout << (C(i) ? "Yes" : "No") << std::endl;
    }
*/
    return 0;
}
