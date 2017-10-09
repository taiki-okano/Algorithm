#include <iostream>
#include <queue>
#include <algorithm>

typedef std::pair<int, int> P;

constexpr int MAX_N = 10;
constexpr int MAX_WH = 1001;
constexpr int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
constexpr int INF = 100000000;

int w, h, n;
char field[MAX_WH][MAX_WH];
P kids[MAX_N];

void solve();

int bfs(P sp, P ep);

int main(){
    std::cin >> w >> h >> n;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            std::cin >> field[j][i];
            if(field[j][i] > '0' && field[j][i] < '10')
                kids[field[j][i] - '0'] = P(j, i);
            if(field[j][i] == 'S')
                kids[0] = P(j, i);
        }
    }
    solve();
    return 0;
}

void solve(){
    int ans = 0;
    
    for(int i = 0; i <= n; ++i){
        ans += bfs(kids[i], kids[(i + 1) % (n + 1)]);
//        std::cout << i << " " << kids[i].first << " " << kids[i].second << std::endl;
    }
    std::cout << ans << std::endl;
}

int bfs(P sp, P ep){
    int dis[MAX_WH][MAX_WH];
    std::queue<P> que;
    que.push(sp);

    for(int i = 0; i < w; ++i){
        for(int j = 0; j < h; ++j)
            dis[i][j] = INF;
    }

    dis[sp.first][sp.second] = 0;

    while(!que.empty()){
        P p = que.front(); que.pop();
        if(p.first == ep.first && p.second == ep.second)
            break;
        for(int i = 0; i < 4; ++i){
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if(nx >= 0 && nx < w && ny >= 0 && ny < h && field[nx][ny] != 'X' && dis[nx][ny] == INF){
                que.push(P(nx, ny));
                dis[nx][ny] = dis[p.first][p.second] + 1;
            }
        }
    }

    return dis[ep.first][ep.second];
}
