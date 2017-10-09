#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

#define MAX_N 25100
#define MAX_T 10000100

typedef std::pair<int, int> P;

void solve();

P caw[MAX_N];
int N, T, shift[MAX_N], ans = 0;

int main(){
    scanf("%d %d", &N, &T);
    for(int i = 0; i < N; ++i)
        scanf("%d %d", &caw[i].first, &caw[i].second);
    solve();
    std::cout << ans << std::endl;
    return 0;
}

void solve(){
    std::priority_queue<int> pque;
    int last = 0;
    
    std::sort(caw, caw + N);
    for(int i = 0; i < N; ++i){
        if(caw[i].first != 1)
            break;
        last = caw[i].second;
    }
    if(last==0){
        ans = -1;
        return;
    }
    ++ans;
    for(int i = 0; i < N; ++i){
        if(last + 1 >= caw[i].first){
            pque.push(caw[i].second);
            continue;
        }
        else if(last + 1 < caw[i].first){
            ++ans;
            if(caw[i].first>pque.top()+1){
                ans=-1;
                return;
            }
            last = pque.top();
            pque.push(caw[i].second);
            continue;
        }
        ans = -1;
        return;
    }
    if(last < T){
        if(pque.top() != T){
            ans=-1;
            return;
        }
        ++ans;
    }
    return;
}