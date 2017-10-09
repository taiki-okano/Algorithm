#include <cstdio>

constexpr int MAX = 1000;

int main(){
	double A, B, C;
	scanf("%lf%lf%lf", &A, &B, &C);
	printf("%lf\n", C / A * B);
	return 0;
}
