#include <iostream>
#include <algorithm>

typedef long long ll;

constexpr int MAX_N = 2001;

int n;
ll c[MAX_N], memo[MAX_N][MAX_N];

ll dfs(int a, int b);

void solve();

int main(){
	std::cin >> n;

	for(int i = 0; i < n; ++i)
		std::cin >> c[i];
	
	solve();

	return 0;
}

void solve(){
	ll ans = 0;

	for(int i = 0; i < n; ++i)
		ans = std::max(dfs(i, i) + c[i], ans);

	std::cout << ans << std::endl;
}

ll dfs(int a, int b){
	if(memo[a][b] > 0)
		return memo[a][b];

	int diff;

	if(a > b)
		diff = n - a + b + 1;
	else 
		diff = b - a + 1;

	if(diff == n)
		return memo[a][b] = 0;

	if(diff % 2)
		return memo[a][b] = (c[(a + n - 1) % n] > c[(b + 1) % n] ? dfs((a + n - 1) % n, b) : dfs(a, (b + 1) % n));
	else
		return memo[a][b] = std::max(dfs((a + n - 1) % n, b) + c[(a + n - 1) % n], dfs(a, (b + 1) % n) + c[(b + 1) % n]);
}