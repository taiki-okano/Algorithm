#include <iostream>
#include <string>

int amount[26]{0};

int main(){
	std::string input;
	std::cin >> input;

	for(auto &x : input) ++amount[x - 'a'];

	int amount_even_num = 0;
	int amount_not_even_num = 1;
	int flag = 0;

	for(auto &x : amount){
		while(true){
			if(x > 1){
				x -= 2;
				++amount_even_num;
			}
			else{
				if(x == 1) ++amount_not_even_num, ++flag;
				break;
			}
		}
	}

	if(flag > 1) flag = 1;

	if(amount_not_even_num != 1) --amount_not_even_num; 

	//std::cout << "There are " << amount_even_num * 2 << " even numbers and " << amount_not_even_num << " not even numbers." << std::endl;
	std::cout << amount_even_num / amount_not_even_num * 2 + flag << std::endl;

	return 0;
}