#include <iostream>

int main(){
	unsigned long long input, ans;
	std::cin >> input;
	if(input % 2 == 0){
		ans = (input / 2) * (input + 1) + 1;
	}
	else{
		ans = (input + 1) / 2 * input + 1;
	}
	std::cout << ans << std::endl;

	return 0;	
}
