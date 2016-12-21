#include <cstdio>
#include <cmath>
#include <queue>

constexpr int MAX_N = 100000;
constexpr long long MAX_T = 1000000000000000000;
constexpr int MAX_Q = 1000;

typedef std::pair<long long, int> P;

int N, Q, target[MAX_Q];
long long T, ans[MAX_N];
P p[MAX_N];

void solve();

int main(){
	scanf("%d %lld %d", &N, &T, &Q);

	for(int i = 0; i < N; ++i){
		scanf("%lld %d", &p[i].first, &p[i].second);
	}
	for(int i = 0; i < Q; ++i){
		scanf("%d", &target[i]);
	}

	solve();
	return 0;
}

void solve(){
	for(int i = 0; i < N - 1; ++i){
		if(p[i].second == 1 && p[i + 1].second == 2 && p[i + 1].first - p[i].first <= T * 2){
			int tmp = ans[i] = ans[i + 1] = (p[i + 1].first + p[i].first) / 2;
			p[i].second = p[i + 1].second = 0;
			for(int j = i - 1; j >= 0; --j){
				if(p[j].second == 1 && tmp - p[j].first <= T){
					p[j].second = 0;
					ans[j] = tmp;
				}
				else{
					break;
				}
			}
			for(int j = i + 2; j < N; ++j){
				if(p[j].second == 2 && p[j].first - tmp <= T){
					p[j].second = 0;
					ans[j] = tmp;
				}
				else{
					break;
				}
			}
		}
	}

	for(int i = 0; i < N; ++i){
		if(ans[i] == 0 && p[i].second != 0){
			if(p[i].second == 1){
				ans[i] = p[i].first + T;
			}
			else{
				ans[i] = p[i].first - T;
			}
		}
	}

	for(int i = 0; i < Q; ++i){
		printf("%lld\n", ans[target[i] - 1]);
	}
}
