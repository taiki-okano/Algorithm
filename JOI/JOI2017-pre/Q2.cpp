#include <cstdio>
#include <algorithm>

constexpr int MAX_NM = 1000;

int main(){
	int N, M;
	int a[MAX_NM], b[MAX_NM];
	
	scanf("%d %d", &N, &M);

	int tmp = 0, sum = 0;;

	for(int i = 0; i < M; ++i){
		scanf("%d %d", &a[i], &b[i]);
		if(a[i] < N){
			tmp = std::max(tmp, N - a[i]);
			sum += N - a[i];
		}
	}

	printf("%d\n", sum - tmp);
	return 0;
}
