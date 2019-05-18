#include <iostream>

unsigned long long N, K;

int main(){

	std::cin >> N >> K;

	unsigned long long count[64] = {};
	for(unsigned long long i = 0; i < N; ++i){

		unsigned long long input;

		std::cin >> input;

		for(unsigned long long j = 0; j < 64; ++j){
			if(input & ((unsigned long long)(1) << j)){
				++count[j];
			}
		}
	}

	unsigned long long ans = 0;
	unsigned long long last = 0;
	unsigned long long last_i = 0;
	for(unsigned long long i = 0; i < 64; ++i){

		if(count[i] >= (N + 1) / 2){
			ans += ((unsigned long long)(1) << i) * count[i];
		}
		else{
			unsigned long long tmp = ((unsigned long long)(1) << i) * (N - count[i]);
			if((((unsigned long long)(1) << i) & K) == 0){
				if(last < tmp){
					ans -= last;
					ans += tmp;
					last = tmp;
					last_i = i;
				}
			}
			else{
				ans += tmp;
			}
		}
	}

	if((((unsigned long long)(1) << last_i) & K) == 0){
		ans -= last;
	}

	std::cout << ans << std::endl;

	return 0;
}
