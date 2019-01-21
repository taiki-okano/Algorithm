#include<iostream>
#include<algorithm>
#include<vector>

int N;
int p[100010];
std::vector<int> G[100010];
bool pass[100010];

void dfs(int node){
    if(node == N){
        return;
    }
    for(int i = 0; i < G[node].size(); i++){
        if(pass[node])continue;
        pass[node] = true;
        dfs(G[node][i]);
        pass[node] = false;
    }
}

int main(){
    std::cin >> N;
    for(int i = 0; i < N ;i++){
        int s, t;
        std::cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

}
