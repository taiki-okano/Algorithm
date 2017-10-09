#include <iostream>
#include <algorithm>
#include <string>

int main(){
	while(true){
		int n, player[10], field = 0;
		std::string card;
		std::cin >> n;
		if(!n) break;
		std::cin >> card;
		for(int i = 0; i < 10; ++i){
			player[i] = 0;
		}
		for(int i = 0; i < card.size(); ++i){
			if(card[i] == 'S'){
				player[i % n]++;
				field += player[i % n];
				player[i % n] = 0;
			}
			else if(card[i] == 'L'){
				player[i % n]++;
				player[i % n] += field;
				field = 0;
			}
			else if(card[i] == 'M'){
				player[i % n]++;
			}
		}
		std::sort(player, player + n - 1);
		for(int i = 0; i < n; ++i)
			std::cout << player[i] << " ";
		std::cout << field << std::endl;
	}
}