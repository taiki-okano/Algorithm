#include <cstdio>

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	a += 12, b += 12;
	a %= 14, b %= 14;

	if(a > b){
		puts("Alice\n");
	}
	else if(a < b){
		puts("Bob\n");
	}
	else{
		puts("Draw");
	}
	return 0;
}
