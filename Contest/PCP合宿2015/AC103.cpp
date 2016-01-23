#include <iostream>

int main(){
	int n, m, d, D;
	std::cin >> n >> m >> d;
	d += 7 * n;
	while(true){
		if(m == 2)
			D = 29;
		else if(m < 8){
			if(m % 2 == 0)
				D = 30;
			else
				D = 31;
		}
		else{
			if(m % 2 ==0)
				D = 31;
			else
				D = 30;
		}
		if(d > D){
			d -= D;
			m += 1;
		}
		else
			break;
	}
	std::cout << m << " " << d << std::endl;
	return 0;
}