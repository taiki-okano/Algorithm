#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>

typedef std::pair<int, int> Pair;

constexpr int MAX_N = 100;
constexpr int MAX_K = 5000;
constexpr int INF = std::numeric_limits<int>::max();

struct edge{int to, cost;};

int N, K;
std::vector<edge> G[MAX_N];

int dijkstra(int s, int g);

int main(){
	while(true){
		std::cin >> N >> K;
		if(N == 0 && K == 0){
			break;
		}

		for(int i = 0; i < K; ++i){

			int in;
			std::cin >> in;
		
			if(in){
				int c, d, e;
				bool flag = true;
				std::cin >> c >> d >> e;
				for(auto& x : G[c]){
					if(x.to == d){
						x.cost = e;
						flag = false;
						break;
					}
				}
				for(auto& x : G[d]){
					if(x.to == c){
						x.cost = e;
						flag = false;
						break;
					}
				}
				if(flag){
					edge tmp;
					tmp.to = d;
					tmp.cost = e;
					G[c].push_back(tmp);
					tmp.to = e;
					tmp.cost = d;
					G[d].push_back(tmp);
				}
			}
			else{
				int a, b;
				std::cin >> a >> b;
				int res = dijkstra(a, b);
				if(res == INF){
					std::cout << -1 << std::endl;
				}
				else{
					std::cout << res << std::endl;
				}
			}
		}
		for(int i = 0; i < MAX_N; ++i){
			G[i].clear();
		}
	}
	return 0;
}

int dijkstra(int s, int g){
	int d[MAX_N];
	std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> que;
	std::fill(d, d + N, INF);
	d[s] = 0;
	que.push(Pair(0, s));

	while(!que.empty()){
		Pair p = que.top(); que.pop();
		int v = p.second;
		if(d[v] < p.first){
			continue;
		}
		for(auto& x : G[v]){
			edge e = x;
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(Pair(d[e.to], e.to));
			}
		}
	}
	
	return d[g];
}
