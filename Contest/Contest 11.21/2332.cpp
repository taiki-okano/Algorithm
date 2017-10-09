#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

const int MAX_N = 100000;
const int INF = 10000000;

int n, p[MAX_N], dis[MAX_N];

void solve(){
    std::queue<std::pair<int, int>> que;

    for(int i = 0; i < MAX_N; ++i){
        p[i] = INF;
    }

    que.push(std::pair<int, int>(0, 0));
    dis[0] = 0;

    while(que.size()){
        std::pair<int, int> s = que.front(); que.pop();
        


    }

    return;
}

int main(){
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> p[i];
    }



    return 0;
}
