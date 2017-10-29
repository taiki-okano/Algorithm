#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits>

constexpr int MAX_V = 15;
constexpr int INF = std::numeric_limits<int>::max();

int V, E;
int edges[MAX_V][MAX_V] = {};

int tsp(int bits, int pos);

int main(){

    //scanf("%d %d\n", &V, &E);
    std::cin >> V >> E;

    for(int i = 0; i < E; ++i){
        for(int j = 0; j < E; ++j){
            edges[i][j] = -1;
        }
    }

    for(int i = 0; i < E; ++i){
        int s, t, d;
        //scanf("%d %d %d\n", &s, &t, &d);
        std::cin >> s >> t >> d;

        edges[s][t] = d;
    }

    int ans = std::numeric_limits<int>::max();
    for(int i = 0; i < V; ++i){
        ans = std::min(ans, tsp(0, i));
    }

    if(ans == std::numeric_limits<int>::max()){
        puts("-1");
        return 0;
    }

    printf("%d\n", ans);

    return 0;
}

int tsp(int bits, int pos){

    int res = std::numeric_limits<int>::max();

    if(bits == (1 << (V + 1)) - 1){
        return 0;
    }

    for(int i = 0; i < V; ++i){

        if(edges[pos][i] == -1){
            continue;
        }

        if((bits & 1 << i) != 0){
            continue;
        }

        int tmp = tsp(bits | (1 << i), i);

        if(tmp == -1){
            continue;
        }

        res = std::min(res, tmp);
    }

    if(res == std::numeric_limits<int>::max()){
        return -1;
    }

    return res;
}
