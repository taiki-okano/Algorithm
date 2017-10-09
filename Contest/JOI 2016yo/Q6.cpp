#include <iostream>
#include <algorithm>

typedef std::pair<int, int> P;

constexpr int MAX_HW = 1000;
constexpr int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int h, w;
int field[MAX_HW][MAX_HW], memo[MAX_HW][MAX_HW] = {-1};

int cost(P now, P before){
    int x = now.first, y = now.second, bx = before.first, by = before.second;
    int res = 0;
    res += field[x][y];
    for(int i = 0; i < 4; ++i){
        if(x + dx[i] != bx && y + dy[i] != by && x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < h && y + dy[i] < w){
            res += field[x + dx[i]][y + dy[i]];
        }
    }
    return res;
}

int dfs(P now = P(0, 0), P before = P(0, 0)){
    if(memo[now.first][now.second] != -1) return memo[now.first][now.second];
    if(now == P(h - 1, w - 1)) return memo[now.first][now.second] = cost(now, before);
    return memo[now.first][now.second] = cost(now, before) + std::min(dfs(P(now.first + 1, now.second), now), dfs(P(now.first, now.second + 1), now));
}

void solve(){
    std::cout << dfs() << std::endl;
}

int main(){
    std::cin >> h >> w;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            char input;
            std::cin >> input;
            if(input == '.') field[i][j] = 0;
            else field[i][j] = input - '0';
        }
    }
    solve();
    return 0;
}
