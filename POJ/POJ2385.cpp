#include <iostream>
#include <cstring>
using namespace std;

const int MAX_T = 1001, MAX_W = 32;

int dp[MAX_T][MAX_W][2], trees[MAX_T];
int t, w;

int main(){
    memset(dp, 0, sizeof(dp));
    memset(trees, 0, sizeof(trees));
    cin >> t >> w;
    
    for(int i = 0; i < t; ++i){
        cin >> trees[i];
        --trees[i];
    }

    int ans = 0;

    for(int i = 0; i < t; ++i){
        for(int j = 0; j <= w; ++j){           
            //移動しない場合のDPテーブルの更新
           dp[i + 1][j][0] = std::max(dp[i + 1][j][0], dp[i][j][0] + (trees[i] == 0));
           dp[i + 1][j][1] = std::max(dp[i + 1][j][1], dp[i][j][1] + (trees[i] == 1));
        
           //移動する場合のDPテーブルの更新
           dp[i + 1][j + 1][0] = std::max(dp[i + 1][j + 1][0], dp[i][j][1] + (trees[i] == 0));
           dp[i + 1][j + 1][1] = std::max(dp[i + 1][j + 1][1], dp[i][j][0] + (trees[i] == 1));
           //移動しない場合でも最適な方法を探索するために、移動回数を増加させてDPテーブルの更新の比較を行う
           dp[i + 1][j + 1][0] = std::max(dp[i + 1][j + 1][0], dp[i][j + 1][0] + (trees[i] == 0));
           dp[i + 1][j + 1][1] = std::max(dp[i + 1][j + 1][1], dp[i][j + 1][1] + (trees[i] == 1));

           int tans = std::max(dp[i + 1][j][0], dp[i + 1][j][1]);
           ans = std::max(tans, ans);
        }
    }
    
    cout << ans << endl;

    return 0;
}
