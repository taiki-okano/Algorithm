#include <cstdio>

int GCD(int a, int b){
	if(b == 0) return a;
	return GCD(b, a % b);
}

int LCM(int a, int b){
	return a * b / GCD(a, b);
}

int main(){
	int n, m, z;
	scanf("%d %d %d", &n, &m, &z);
	printf("%d\n", static_cast<int>(z / LCM(n, m)));
	return 0;
}
