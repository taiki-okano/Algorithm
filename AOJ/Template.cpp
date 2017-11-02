#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <limits>
#include <iomanip>
#include <utility>
#include <numeric>
#include <functional>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define RFOR(i, m, n) for(int i = (m); i > (n); --i)
#define REP(i, n) FOR(i, 0, n)

#define EXIST(c, k) ((s).fined((k)) != (s).end())
#define SORT(c) ((c).sort((c).begin(), (c).end()))
#define RSORT(c) ((c).sort((c).end(), (c).begin(), greater<typeof((c).begin())>))

template<typename T> inline T SQR(T a){ return a * a };
template<typename T> inline T POW(T a, int n){
	int res = 1;
	while(n--){
		res *= a;
	}
	return res;
}

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	return 0;
}
