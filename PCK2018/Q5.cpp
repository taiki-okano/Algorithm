#include <iostream>

typedef long long ll;
ll pow(ll a, ll b){
	if(b > 0) return pow(a, b - 1) * a;
	else return 1;
}

int sum(ll x){
	ll mod = 1e8;
	int s = 0;
	while(mod > 1){
		s += x / mod;
		x %= mod;
		mod /= 10;
	}
	return s + x;
}

int main(){

	ll a, n, m;
	ll ans = 0;
	std::cin >> a >> n >> m;

	ll y = 1;
	while(true){
		ll c = a + y;
		ll x = pow(c, n);
		if(x > m) break;
		if(y == sum(x)) ans++;
		y++;
	}
	std::cout << ans << std::endl;
	return 0;
}
