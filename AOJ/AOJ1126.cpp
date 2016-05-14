#include <iostream>
#include <algorithm>
#include <ctype.h>

const int max_width = 70, max_height = 70;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int width, height;

std::string matrix[max_width][max_height];
std::string memo[max_width][max_height];
std::string ans;

std::string compare(std::string s1, std::string s2);

std::string dfs(int x, int y);

void solve();

int main(){
    while(true){
        ans = -1;
        for(int i = 0; i < max_width; ++i){
            for(int j = 0; j < max_height; ++j)
                memo[i][j] = "A";
        }
        std::cin >> height >> width;
        if(width + height == 0) break;
        for (int i = 0; i < width; ++i){
            for(int j = 0; j < height; ++j){
                char in;
                std::cin >> in;
                matrix[i][j] = in;
            }
        }
        solve();
    } 
    return 0;
}

void solve(){
    for(int i = 0; i < width; ++i){
        for(int j = 0; j < height; ++j){
            if(!isdigit(matrix[i][j][0]) || matrix[i][j] == "0") continue;
            ans = compare(dfs(i, j), ans);
        }
    }
    std::cout << ans << std::endl;
    return;
}

std::string dfs(int x, int y){
    if(memo[x][y] != "A") return memo[x][y];
    std::string res = "";
    for(int i = 2; i < 4; ++i){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
        if(!isdigit(matrix[nx][ny][0])) continue;
        res = compare(dfs(nx, ny), res);
    }
    return memo[x][y] = matrix[x][y] + res;
}

std::string compare(std::string s1, std::string s2){
    if(s1.length() == s2.length()){
        for(int i = 0; i < s1.length(); ++i){
            if(s1[i] != s2[i])
                return s1[i] > s2[i] ? s1 : s2;
        }
    }
    else if(s1.length() > s2.length()) return s1;
    return s2;
}