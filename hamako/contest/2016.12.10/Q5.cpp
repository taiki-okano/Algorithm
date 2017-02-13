#include <cstdio>
#include <algorithm>

constexpr int MAX_N = 100000;
constexpr int MAX_M = 200000;
constexpr long long MAX_P = 1000000000;

int N, M, s;
long long dis[MAX_N];
long long a[MAX_M][3], d[MAX_M];

void solve();

int main(){
	scanf("%d %d %d", &N, &M, &s);
	for(int i = 0; i < N; ++i){
		dis[i] = MAX_P;
	}
	dis[s] = 0;
	for(int i = 0; i < M; ++i){
		scanf("%lld %lld %lld %lld", &a[i][0], &a[i][1], &a[i][2], &d[i]);
		for(auto& x : a[i]){
			--x;
		}
		for(auto& x : a[i]){
			if(x == s){
				for(auto& y : a[i]){
					if(x != y){
						dis[y] = dis[x];
					}
				}
			}
			else if(dis[x] != MAX_P){
				for(auto& y : a[i]){
					if(x != y){
						dis[y] = std::min(std::max(dis[x], d[i]), dis[y]);
					}
				}
			}
		}
	}
	for(int i = 0; i < M; ++i){
		for(auto& x : a[i]){
			if(dis[x] != MAX_P){
				for(auto& y : a[i]){
					if(x != y){
						dis[y] = std::min(dis[y], std::max(dis[x], d[i]));
					}
				}
			}
		}
	}

	for(int i = 0; i < N; ++i){
		if(dis[i] == MAX_P){
			puts("-1");
		}
		else{
			printf("%lld\n", dis[i]);
		}
	}

	return 0;
}
