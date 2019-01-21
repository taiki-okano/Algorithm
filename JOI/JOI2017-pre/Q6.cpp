#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <limits>
#include <cmath>

constexpr int MAX_N = 10000;
constexpr int MAX_M = 20000;
constexpr int MAX_X = 200;
constexpr int INF = std::numeric_limits<int>::max();

struct edge{ int to, int cost, int t, int x; };
typedef std::pair<int, int> P;

int N, M, X;
int t[MAX_N], d[MAX_N];

std::vector<edge> G[MAX_N];

void dijkstra(int s);

void solve();

int main(){
	std::ios::sync_with_stdio(false);
	std::cin >> N >> M >> X;
	
	for(int i = 0; i < N; ++i){
		std::cin >> t[i];
	}
	for(int i = 0; i < M; ++i){
		int a, b, c;
		std::cin >> a >> b >> c;
		--a, --b;
		G[a].push_back(edge(b, c));
		G[b].push_back(edge(a, c));
	}

	solve();
	return 0;
}

void solve(){
	dijkstra(0);
}

void dijkstra(int s){
	std::priotity_queue<P, std::vector<P>, std::greater<P>> que;
	std::fill(d, d + N, INF);
	d[s] = 0;
	que.push(P(0, 2));
	while(!que.empty()){
		P p = que.top(); que.pop();

		int v = p.second;
		if(d[v] < p.first){
			continue;
		}
		for(auto& x : G[v]){
			edge e = x;
			if(d[e.to] > d[v] + e.cost && abs(e.to - t[e.to]) == 2){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}
