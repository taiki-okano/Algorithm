#include <cstdio>
#include <algorithm>

constexpr int MAX_N = 200000;

int gcd(int a, int b){
	if(a == b){
		return a;
	}
	if(a > b){
		return gcd(a - b, b);
	}
	if(a < b){
		return gcd(b - a, a);
	}
	return 1;
}

int main(){
	int N, K, a[MAX_N];

	scanf("%d%d", &N, &K);

	for(int i = 0; i < N; ++i){
		scanf("%d", &a[i]);
	}

	std::sort(a, a + N);

	int ans = 0;
	for(int i = 0; i < N - 1; ++i){
		int tmp = K / gcd(a[i], K);
		for(int j = i + 1; j < N; ++j){
			if(tmp / gcd(tmp, a[j]) == 1){
				++ans;
			}
		}
	}

	/*
	for(int i = 0; i < N; ++i){
		printf("Debug a[%d] : %d\n", i, a[i]);
	}
	*/

	printf("%d\n", ans);
	return 0;
}
