#include <iostream>
#include <queue>

#define MAX_W 20
#define MAX_H 20

typedef std::pair<int, int> P;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int w, h;
int sx, sy;
int count = 0;
char map[MAX_W][MAX_H];

void solve();

int main(){
    while(true){
        std::cin >> w >> h;
        
        if(w == 0 && h == 0)
            break;
        
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                std::cin >> map[j][i];
                if(map[j][i] == '@')
                    sy = i, sx = j;
            }
        }
        solve();
        std::cout << count << std::endl;
        count = 0;
    }
    
    return 0;
}

void solve(){
    std::queue<P> que;
    que.push(P(sx, sy));
    bool flag[MAX_W][MAX_H] = {false};
    
    while(que.size()){
        P p = que.front();
        que.pop();
        
        for(int i = 0; i < 4; ++i){
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if(nx >= 0 && nx < w && ny >= 0 && ny < h && map[nx][ny] != '#' && !flag[nx][ny]){
                flag[nx][ny] = true;
                que.push(P(nx, ny));
                ++count;
            }
        }
    }
}