#include <cstdio>
#include <cmath>
#include <algorithm>	

constexpr int MAX = 100000;

double N, M, R;

double func(double i){
	if(i <= 0 || i >= N){
		return 0;
	}
	double tmp;
	if(i < (N / 2)){
		tmp = R * (((N / 2) - i) / (N / 2));
	}
	else{
		tmp = R * ((i - (N / 2)) / (N / 2));
	}
	return sqrt((R * R) - (tmp * tmp)) * 2;
}

int main(){
	scanf("%lf%lf%lf", &R, &N, &M);

	double ans = 0;
	for(int i = 1; i < N + M; ++i){
		ans += std::max(func(double(i)), func(double(i - M)));
		//printf("func(%d) : %lf\n", i, std::max(func(double(i)), func(double(i - M))));
	}

	printf("%lf\n", ans);
	return 0;
}
