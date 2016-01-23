#include <iostream>

constexpr int MAX_NM = 100;
int N, M;
int A[MAX_NM];

void swap(int a, int b){
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

int main(){
    std::cin >> N >> M;
    for(int i = 0; i < N; ++i) std::cin >> A[i];
    
    for(int i = 2; i <= M; ++i) {
        for(int j = 0; j < N - 1; ++j) {
            if(A[j] % i > A[j + 1] % i) swap(j, j + 1);
        }
    }

    for(int i = 0; i < N; ++i) std::cout << A[i] << std::endl;

    return 0;
}
