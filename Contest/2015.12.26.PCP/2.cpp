#include <iostream>
#include <algorithm>

constexpr int MAX_N = 100000;
constexpr int MAX_K = 100;
constexpr int INF = 1000;

int n, k;
int score[MAX_N], max[MAX_N], min[MAX_N];

int main(){

    std::cin >> n >> k;

    for(int i = 0; i < n; ++i){
        max[i] = score[i] = 0;
        min[i] = INF;
    }

    for(int i = 0; i < k; ++i){
        for(int j = 0; j < n; ++j){
            int in;
            std::cin >> in;

            max[j] = std::max({in, max[j]});
            min[j] = std::min({in, min[j]});
            score[j] += in;
        }
    }

    int s_max = 0;
    for(int i = 0; i < n; ++i){
        score[i] -= max[i];
        score[i] -= min[i];
        s_max = std::max({score[i], s_max});
    }

    //for(int i = 0; i < n; ++i) std::cout << i + 1 << " : " << score[i] << " ";

    for(int i = 0; i < n; ++i){
        if(s_max == score[i]) std::cout << i + 1 << std::endl;
    }

    return 0;
}
