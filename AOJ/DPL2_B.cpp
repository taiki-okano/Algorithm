#include <cstdio>
#include <algorithm>

constexpr int MAX_V = 15;
constexpr int INF = 1000000000;

int V, E;
int memo[1 << MAX_V][MAX_V];
int dis[MAX_V][MAX_V];

int tsp(int s = 1, int v = 0);

int main(){
    scanf("%d%d", &V, &E);
    for(int i = 0; i < 1 << V; ++i){
        for(int j = 0; j < V; ++j){
            memo[i][j] = INF;
        }
    }
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            dis[i][j] = INF;
        }
    }
    for(int i = 0; i < E; ++i){
        int s, t, d;
        scanf("%d%d%d", &s, &t, &d);
        if(dis[s][t] > d){
            dis[s][t] = d;
            dis[t][s] = d;
        }
    }
    printf("%d\n", tsp());
    return 0;
}

int tsp(int s, int v){
    if(memo[s][v] != INF){
        return memo[s][v];
    }
    if(s == (1 << V) - 1){
        return dis[v][0];
    }
    for(int i = 0; i < V; ++i){
        if(s & (1 << i)){
            continue;
        }
        memo[s][v] = std::min(memo[s][v], tsp(s | (1 << i), i) + dis[v][i]);
    }
    return memo[s][v];
}
