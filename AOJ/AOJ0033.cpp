#include <iostream>

int ball[10];
bool ans;

void solve();

void dfs(int n, int right, int left);

int main(){
	int n;
	std::cin >> n;

	while(n--){
		for(int i = 0; i < 10; ++i)
			std::cin >> ball[i];
		solve();
		if(ans)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

	return 0;
}

void solve(){
	ans = false;
	dfs(0, 0, 0);
	return;
}

void dfs(int n, int right, int left){
	if(ball[n] < right && ball[n] < left)
		return;

	if(n == 9){
		if(ball[n] > right || ball[n] > left){
			ans = true;
			return;
		}
	}

	dfs(n + 1, ball[n], left);
	dfs(n + 1, right, ball[n]);

	if(ans)
		return;

	return;
}