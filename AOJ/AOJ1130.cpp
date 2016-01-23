#include <iostream>
#include <string>

const std::string member[7] = {"yamada",  "tanaka", "itahara", "okano", "goat", "naito", "tanabe"};
bool flag[7] = {false};

int main(){
	srand(time(NULL));
	
	int count = 0;
	for(int i = 0; i < 4; ++i){
		int rnd = rand() % 7;
		while(true){
			if(!flag[rnd]){
				flag[rnd] = true;
				break;
			}
		}
	}
	for(int i = 0; i < 7; ++i){
		std::cout << member[i] << " ";
		if(flag[i])
			std::cout << "A" << std::endl;
		else
			std::cout << "B" << std::endl;
	}
	return 0;
}