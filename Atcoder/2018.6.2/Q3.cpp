#include <iostream>
#include <algorithm>

constexpr int MAX_N = 100000;

int N;
long D, X[MAX_N];

int main(){
	
	std::cin >> N >> D;

	for(int i = 0; i < N; ++i){
		std::cin >> X[i];
	}

	long ans = 0;

	for(int i = 0; i < N - 2; ++i){
		for(int k = i + 2; k < N; ++k){

			if(X[k] - X[i] <= D){
				continue;
			}

			for(int j = i + 1; j < k; ++j){
			
				if(X[j] - X[i] > D){
					continue;
				}		
			
				if(X[k] - X[j] > D){
					continue;
				}		
			
				++ans;
			
			}
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
