#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX_N 1001
#define MAX_W 10001

int dp[MAX_W][MAX_N], W, N, value[MAX_N], w[MAX_N];

int main(){
    int Case = 0;
    
    while(true){
    	for(int i = 0; i < MAX_N; ++i)
        	memset(dp[i], 0, MAX_W);
    	//initialize
    	
        ++Case;
        scanf("%d%d", &W, &N);
        if(!W)
            break;
        for(int i = 0; i < N; ++i)
            scanf("%d,%d", &value[i], &w[i]);
        //input
        
        for(int i = 1; i <= N; ++i){
            for(int j = 0; j <= W; ++j){
                dp[i][j] = std::max(dp[i - 1][j - w[i - 1]] + value[i - 1], dp[i - 1][j]);
            }
        }
        //solve
        
        int ans = dp[N][W];
        
        printf("Case %d:\n%d\n", Case, ans);
        
        int i = 0;
        while(true){
            if(ans != dp[N][W - i]){
                printf("%d\n", W - i + 1);
                break;
            }
            ++i;
        }
    }
    return 0;
}


