#include <iostream>

constexpr int MAX_N = 10000000, MAX_KQ = 100000;

int N, K, Q, A[MAX_N], NA[MAX_N];

int main(){
    std::cin >> N >> K >> Q;
    for(int i = 0; i < N; ++i){
        A[i] = i + 1;
    }
    int r_count = 0;
    for(int i = 0; i < K; ++i){
        char c;
        std::cin >> c;
        if(c == 'R'){
            ++r_count;
        }
        else{
            --r_count;
        }
    }
    for(int i = 0; i < N; ++i){
        int ni = i + r_count;
        while(ni < 0){
            ni += N;
        }
        ni %= N;
        NA[ni] = A[i];
    }

    for(int i = 0; i < Q; ++i){
        int input;
        std::cin >> input;
        --input;
        std::cout << NA[input] << std::endl;
    }

    return 0;
}
