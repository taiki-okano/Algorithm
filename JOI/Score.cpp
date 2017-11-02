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
#define EACH(c, x) for(auto& x : (c))
#define EXIST(c, k) ((s).fined((k)) != (s).end())
#define SORT(c) (sort((c).begin(), (c).end()))
#define CLR(a) memset((a), 0, sizeof((a)))
#define DUMP(a) cerr << #a << " = " << (a) << endl
#define DEBUG(a) cerr << #a << " = " << (a) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define PII pair<int, int>

constexpr double PI = acos(-1.0);
constexpr double EPS = 1e-10;
template<typename T> inline T SQR(T a){ return a * a; }
template<typename T> inline T POW(T a, int n){int res = 1;while(n--) res *= a;return res;}
inline int toInt(string s) {int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

constexpr int MAX_N = 100000;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	vector<PII> scores;

	cin >> N;

	REP(i, N){
		int input;
		cin >> input;

		scores.push_back(PII(input, i));
	}

	sort(scores.begin(), scores.end(), greater<PII>());

	int ans[MAX_N] = {};
	int count = 0;
	int last = 1;
	REP(i, N - 1){
		if(scores[i].first == scores[i + 1].first){
			++count;
		}
		else{
			FOR(j, i - count, i + 1){
				ans[scores[j].second] = last;
			}
			last += count + 1;
			count = 0;
		}
	}

	REP(i, N){
		if(ans[i] == 0){
			ans[i] = last;
		}
		cout << ans[i] << endl;
	}

	return 0;
}
