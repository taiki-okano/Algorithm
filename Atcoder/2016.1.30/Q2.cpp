#include <iostream>
#include <queue>
#include <functional>

typedef std::pair<int, int> P;

int main(){
    std::priority_queue< P, std::vector<P>, std::greater<int> > que;

    int n;
    std::cin >> n;

    for(int i = 0; i < n; ++i){
        int in;
        std::cin >> in;

        que.push(P(in, i));
    }

    int before = 0, count = 1;
    while(!que.empty()){
        P p = que.top(); que.pop();
        if(before > p.second)
            ++count;
        std::cout << p.second << std::endl;
        before = p.second;
    }

    std::cout << count << std::endl;

    return 0;
}
