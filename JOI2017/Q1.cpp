#include <cstdio>
#include <limits>

#ifndef EVAL
#define DEBUG(X) std::cout << __LINE__ << ": " << X << std::endl;
#else
#define DEBUG(X) {X;}
#endif

constexpr int MAX_NQ = 200000;
constexpr int MAX_ST = 1000000;

int N, Q, S, T;
long long diff[MAX_NQ + 1];
long long ans = 0;

long long calc(int n){
	if(diff[n] < 0){
		return -diff[n] * T;
	}
	else{
		return -diff[n] * S;
	}
}

int main(){
	scanf("%d%d%d%d", &N, &Q, &S, &T);

	int tmp;
	scanf("%d", &tmp);
	for(int i = 1; i <= N; ++i){
		int in;
		scanf("%d", &in);
		diff[i] = in - tmp;
		ans += calc(i);
		tmp = in;
	}

	for(int i = 0; i < Q; ++i){
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);

		long long before = calc(l);
		diff[l] += x;
		long long after = calc(l);

		ans = ans - before + after;
		
		if(r < N){
			before = calc(r + 1);
			diff[r + 1] -= x;
			after = calc(r + 1);
			ans = ans - before + after;
		}

		printf("%lld\n", ans);
	}

	return 0;
}
