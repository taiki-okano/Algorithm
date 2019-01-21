#include <iostream>
#include <algorithm>

int main(){

	long long M, N, Q;

	std::cin >> M >> N >> Q;

	long long a = 0, b = 0;

	long long cost = 0;

	while(Q--){

		long long na, nb;

		std::cin >> na >> nb;

		long long da = std::abs(na - a);
		long long db;
		if(nb > b){
			db = std::min(nb - b, N - nb + b);
		}
		else{
			db = std::min(b - nb, N - b + nb);
		}

		cost += std::min(da + db, na + a);

		a = na, b = nb;
	}

	std::cout << cost << std::endl;


	return 0;
}
