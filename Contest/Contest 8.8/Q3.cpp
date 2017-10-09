#include <iostream>

constexpr int MAX_N = 10000;

int main(){
	int N, M, K, S, G;

	std::cin >> N >> M >> K >> S >> G;

	int way[MAX_N][MAX_N];

	for(int i = 0; i < N; ++i){
		int a, b, cost;
		std::cin >> a >> b >> cost;
		way[a][b] = cost;
		way[b][a] = cost;
	}

	return 0
}
