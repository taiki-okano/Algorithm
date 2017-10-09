#include <iostream>
#include <algorithm>
#include <cstring>

constexpr int MAX_T = 100000;

char S[MAX_T];
int dp[MAX_T];

int dfs(int a);

void solve();

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> S;

	solve();

	return 0;
}

void solve(){
	std::cout << dfs(1) << std::endl;
}

int dfs(int a){
	if(a == strlen(S)){
		return dp[strlen(S) - 1];
	}

	if(S[a] == '5' && S[a - 1] == '2'){
		dp[a] = dp[a - 1] + 2;
		return dfs(a + 1);
	}
	else if(S[a] == '?'){
		int res = 0;
		if(S[a - 1] == '2'){
			S[a] = '5';
			dp[a] = dp[a - 1] + 2;
			res = std::max(dfs(a + 1), res);
			S[a] = '?';
		}
		if(S[a + 1] == '5'){
			S[a] = '2';
			dp[a] = dp[a - 1];
			res = std::max(dfs(a + 1), res);
		}
		if(S[a - 1] == '5'){
			S[a] = '2';
			dp[a] = dp[a - 1];
			res = std::max(dfs(a + 1), res);
		}
		return res;
	}
	else{
		dp[a] = dp[a - 1];
		return dfs(a + 1);
	}
}
