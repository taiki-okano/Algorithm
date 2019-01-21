#include <iostream>
#include <string>
#include <algorithm>

int main(){

	int A, B, N;
	std::string input;

	std::cin >> A >> B >> N >> input;

	for(auto& c : input){
		switch(c){
			case 'S':
				A--;
				break;
			case 'C':
				B--;
				break;
			case 'E':
				if(A >= B){
					A--;
				}
				else{
					B--;
				}
		}
	}

	std::cout << std::max(0, A) << std::endl;
	std::cout << std::max(0, B) << std::endl;

	return 0;
}
