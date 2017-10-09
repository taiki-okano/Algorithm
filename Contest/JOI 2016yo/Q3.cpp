#include <iostream>
#include <algorithm>

constexpr int MAX_NM = 50;
constexpr int INF = 100000000;

int N, M;
char field[MAX_NM][MAX_NM];

int count(int a, int b){
    int count_r = 0, count_b = 0, count_w = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(i < a){
                if(field[i][j] == 'W') ++count_w;
            }
            else if(i < b){
                if(field[i][j] == 'B') ++count_b;
            }
            else{
                if(field[i][j] == 'R') ++count_r;
            } } }

    return N * M - (count_w + count_r + count_b); }

int dfs(){
    int ans = INF;

    for(int i = 1; i < N - 1; ++i){
        for(int j = i + 1; j < N; ++j){
            ans = std::min(ans, count(i, j));
        }
    }

    return ans;
}

void solve(){
    std::cout << dfs() << std::endl;
}

int main(){
    std::cin >> N >> M;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            std::cin >> field[i][j];
        }
    }

    solve();

    return 0;
}
