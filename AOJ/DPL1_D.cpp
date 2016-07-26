#include <cstdio>

constexpr int MAX_N = 100000;

int N;
int A[MAX_N];

void solve();

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &A[i]);
    }
    solve();
}

void solve(){
    int dp[MAX_N], length = 0;
    dp[0] = 0;
    for(int i = 0; i < N; ++i){
        if(dp[length] < A[i]){
            dp[++length] = A[i];
            printf("dp[%d] : %d, A[%d] : %d", length - 1, dp[length - 1], i, A[i]);
        }
        else{
            int low = 0, mid, high = length;
            while(low < high){
                mid = (low + high) / 2;
                if(dp[mid] > A[i]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            dp[mid] = A[i];
        }
    }
    for(int i = 0; i < N; ++i){
        printf("%d\n", dp[i]);
    }
    printf("%d\n", length);
}
