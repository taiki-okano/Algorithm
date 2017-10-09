#include <iostream>
#include <string>

std::string D;

const char keyward[] = {"AIDUNYAN"};

void solve();

int main(){
	std::cin >> D;
	solve();
	return 0;
}

void solve(){
	while(true){
		for(int i = 0; i < D.size() - 8; ++i){
			for(int j = i; j < i + 8; ++j){
				for(int k = 0; k < 8; ++k){
					if(keyward[j] == D[k]){
						count++;
					}
				}
			}
		}
	}
	std::cout << D << std::endl;
	return;
}
