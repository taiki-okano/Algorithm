#include <iostream>

constexpr int MAX_N = 100000;
constexpr int MAX_M = 20;

int N, M, d[MAX_N], v[MAX_M];
bool s[MAX_N];

void swap(int& a, int& b);

void solve();

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M;

	for(int i = 0; i < N; ++i){
		std::cin >> d[i];
		--d[i];
	}
	solve();
	return 0;
}

void solve(){
	int ans = 0;
	bool flag[MAX_M];
	for(int i = 0; i < M; ++i){
		flag[i] = false;
	}
	int tmp;
	for(int i = 0; i < N; ++i){
		if(flag[d[i]]){
			int p, n, target;
			if(i > 1){
				p = i - 1;
			}
			if(i < N - 1){
				n = i + 1;
			}
			for(int j = 0; j < N; ++j){
				int jp = 0, jn = 0;
				if(j > 1){
					jp = j - 1;
				}
				if(j < N - 1){
					jn = j + 1;
				}
				if(d[jp] == d[i]){
					target = jp;
				}
				if(d[jn] == d[i]){
					target = jn;
				}
				if(d[jp] == d[i] && (d[j] == d[p] || d[j] == d[n])){
					target = jp;
				}
				if(d[jn] == d[i] && (d[j] == d[p] || d[j] == d[n])){
					target = jn;
				}
				if(d[jp] == d[i] && (d[j] == d[p] || d[j] == d[n]) && s[d[jp]]){
					target = jp;
					--ans;
					break;
				}
				if(d[jn] == d[i] && (d[j] == d[p] || d[j] == d[n]) && s[d[jn]]){
					target = jn;
					--ans;
					break;
				}
			}
			ans += 2;
			swap(d[i], d[target]);
		}
		else if(!flag[d[i]] && tmp != d[i]){
			flag[d[i]] = true;
		}
		tmp = d[i];
	}
	std::cout << ans << std::endl;
}

void swap(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}
