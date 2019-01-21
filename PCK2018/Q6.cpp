#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
int N;
int OK = 0;
int A[300010];
std::vector<int> a;
int main(){
    std::cin >> N;
    for(int i = 0;i < N; i++){
        std::cin >> A[i];
        a.push_back(A[i]);
    }
    std::sort(a.begin(), a.end());
    for(int i = 0; i < N; i++){
        if(a[i] == A[i]) OK++;
    }
    if(OK == N){
        std::cout << 0 << std::endl;
        return 0;
    }
    int Q;
    std::cin >> Q;
    for(int i = 1; i <= Q; i++){
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        if(a[x] == A[x])OK--;
        if(a[y] == A[y])OK--;
        std::swap(A[x], A[y]);
        if(a[x] == A[x])OK++;
        if(a[y] == A[y])OK++;
        if(OK == N){
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}