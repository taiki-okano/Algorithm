#include <iostream>
using namespace std;

int main(){
	double a, b, c, d;
	cin >> a >> b >> c >> d;

	double T = b / a;
	double A = d / c;

	if (T < A) cout << "AOKI" << endl;
	else if(T > A) cout << "TAKAHASHI" << endl;
	else cout << "DRAW" << endl;
	return 0;
}