#include <iostream>
#include <numeric>
#include <algorithm>

constexpr int MAX_NM = 100;

int main(){

	int N, M, T;

	long long a_castle[MAX_NM] = {}, b_castle[MAX_NM] = {};

	std::cin >> N >> M;

	for(int i = 0; i < N; ++i){
		std::cin >> a_castle[i];
	}

	for(int i = 0; i < M; ++i){
		std::cin >> b_castle[i];
	}

	std::cin >> T;

	while(T--){

		long long d, p, q;

		std::cin >> d >> p >> q;
		--p, --q;

		if(d == 2){
			long long tmp = p;
			p = q;
			q = tmp;
		}

		long long tmp = a_castle[p];
		a_castle[p] = std::max<long long>(0, a_castle[p] - b_castle[q]);
		b_castle[q] = std::max<long long>(0, b_castle[q] - tmp);
	}

	std::cout << std::accumulate(a_castle, a_castle + N, 0LL) << std::endl;
	std::cout << std::accumulate(b_castle, b_castle + M, 0LL) << std::endl;

	return 0;
}
