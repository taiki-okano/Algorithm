#include <iostream>
#include <algorithm>
#include <cstring>

class data{
public:
    int stime, etime, eff;

    data() : stime(0), etime(0), eff(0){}

    bool operator<(const data &d)const{
        return stime < d.stime;
    }
};

int N, M, R;
const int MAX_N = 10000000, MAX_M = 1000;
data datas[MAX_M];
int dp[MAX_M];

int main(){
    memset(dp, 0, sizeof(dp));
    
    std::cin >> N >> M >> R;

    for(int i = 0; i < M; ++i){
        std::cin >> datas[i].stime >> datas[i].etime >> datas[i].eff;
    }
    std::sort(datas, datas + M);
    
    for(int i = 0; i < M; ++i){
        int max = 0;
        
        for(int j = 0; j < i; ++j){
            if(datas[j].etime + R <= datas[i].stime)
                max = std::max(max, dp[j]);
        }

        dp[i] = max + datas[i].eff;
    }

    int ans = 0;
    for(int i = 0; i < M; ++i){
        ans = std::max(ans, dp[i]);
    }

    std::cout << ans << std::endl;

    return 0;
}

