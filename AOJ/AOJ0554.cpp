#include <cstdio>

int main(){
	int sum = 0;
	for(int i = 0; i < 4; ++i){
		int in;
		scanf("%d", &in);
		sum += in;
	}
	printf("%d\n", sum / 60);
	printf("%d\n", sum % 60);
	return 0;
}
