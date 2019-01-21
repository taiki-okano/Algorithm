#include <iostream>
#include <vector>

using P = std::pair<double, double>;

int main(){

	int H, W, k;

	std::vector<P> vec;

	std::cin >> H >> W >> k;

	double x = W - 1, y = 1.0;

	vec.push_back(P(x, y));

	while(x > 1.0 || y < H - 1.0){

		std::cout << x << ' ' << y << std::endl;

		if(x == 1.0){
			y += 1.0;
		}
		if(y == H - 2.0){
			x -= 1.0;
		}
		else if((y + 1.0) / x == y / (x - 1.0)){
			y += 1.0;
		}
		else if((y + 1.0) / x > y / (x - 1.0)){
			x -= 1.0;
		}
		else{
			y += 1.0;
		}
		vec.push_back(P(x, y));
	}

	std::cout << (int)vec[k - 1].first << ' ' << (int)vec[k - 1].second << std::endl;

	return 0;
}
