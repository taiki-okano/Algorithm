#include <iostream>
#include <cstdio>

int main(){

	int n;

	std::cin >> n;

	if(n / 10 == 9 || n % 10 == 9){
		puts("Yes");
	}
	else{
		puts("No");
	}

	return 0;
}
