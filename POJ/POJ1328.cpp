#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

#define MAX_N 1000

typedef std::pair<int, int> P;

void solve();

int n, d, ans;
P island[MAX_N];

int main(){
	while(true){
		scanf("%d%d", &n, &d);
		if(n == 0 && d == 0) break;
		solve();
		std::cout << ans << std::endl;
	}
	return 0;
}

void solve(){
	int dd = d * d;
	ans = 0;
	std::sort(island, island + n);

	int i = 0;
	while(true){
		if(i >= n)
			break;

		if(island[i].second > d){
			ans = -1;
			break;
		}
		++ans;
		int rader = sqrt(dd - (island[i].second * island[i].second));
		for(int j = i + 1; j < n; ++j){
			if(j >= n)
				break;
			if(d > sqrt((island[i].second * island[i].second) + ((rader - island[i].first) * (rader - island[i].first)))){
				++i;
			}
			else
				break;
		}
	}
	return;
}