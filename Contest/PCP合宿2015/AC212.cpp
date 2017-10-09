#include <iostream>

int main(){
	int n;
	std::cin >> n;
	int min = 0, sec = 0, msec = 0;
	while(n--){
		char in;
		for(int i = 0; i < 9; ++i){
			std::cin >> in;
			if(i < 2){
				min += in * (i == 0 ? 10 : 1);
			}
			else if(i < 5 && i > 2){
				sec += in * (i == 3 ? 10 : 1);
				while(true){
					if(sec > 59){
						sec -= 60;
						++min;
					}else break;
				}
			}
			else if(i < 9 && i > 5){
				msec += in * (i == 6 ? 100 : (i == 7 ? 10 : 1));
				while(true){
					if(msec > 999){
						msec -= 1000;
						++sec;
					}else break;
				}
			}
		}
	}
	if(min < 10)
		std::cout << 0;
	if(min < 1)
		std::cout << 0;
	std::cout << min << ":";


	if(sec < 10)
		std::cout << 0;
	if(sec < 1)
		std::cout << 0;
	std::cout << sec << ":";

	if(msec < 100)
		std::cout << 0;
	if(msec < 10)
		std::cout << 0;
	if(msec < 1)
		std::cout << 0;
	std::cout << msec << std::endl;
	return 0;
}