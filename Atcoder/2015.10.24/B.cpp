#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double n, m;

	cin >> n >> m;

	if(n >= 12) n -= 12;

	double ans = abs((30 * n + 0.5 * m) - (6 * m));

	if(ans > 180) ans = 180 - ans;

	cout << ans << endl;

	return 0;
}