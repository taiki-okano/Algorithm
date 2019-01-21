#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

typedef std::pair<int, int> P;
typedef std::pair<P, P> PP;

std::map<PP, int> M;
int N, K;
int X[3010], Y[3010];

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(a, b % a);
}

int main(){
    std::cin >> N >> K;
    for(int i = 0; i < N; i++){
        std::cin >>X[i] >> Y[i];
    }
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
			if(X[i] == X[j]){
				M[std::make_pair(std::make_pair(0, 0), std::make_pair(X[i], 0))]++;
				if(M[std::make_pair(std::make_pair(0, 0), std::make_pair(X[i], 0))] >= K){
					std::cout << 1 << std::endl;
					return 0;
				}
				continue;
			}
			if(X[i] == X[j]){
				M[std::make_pair(std::make_pair(0, 0), std::make_pair(X[i], 0))]++;
				if(M[std::make_pair(std::make_pair(0, 0), std::make_pair(X[i], 0))] >= K){
					std::cout << 1 << std::endl;
					return 0;
				}
				continue;
			}
			int x_diff = (X[i] - X[j]);
            int y_diff = (Y[i] - Y[j]);

			int g = gcd(std::abs(x_diff), std::abs(y_diff));

			x_diff /= g, y_diff /= g;

			bool flag = (x_diff * y_diff < 0);
			x_diff = std::abs(x_diff);
			y_diff = std::abs(y_diff);

			if(flag){
				x_diff *= -1;
			}
			int ys = (Y[i] * x_diff) - (X[i] * y_diff);
			int xs = x_diff;
			g = gcd(std::abs(ys), xs);
			ys /= g, xs /= g;
			flag = (ys * xs < 0);
			xs = std::abs(xs);
			ys = std::abs(ys);
			if(flag) xs *= -1;
			M[std::make_pair(std::make_pair(x_diff, y_diff), std::make_pair(xs, ys))]++;
			if(M[std::make_pair(std::make_pair(x_diff, y_diff), std::make_pair(xs, ys))] >= K){
				std::cout << 1 << std::endl;
				return 0;
			}
        }
    }
	std::cout << 0 << std::endl;
	return 0;
}