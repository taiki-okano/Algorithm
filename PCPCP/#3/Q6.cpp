#include <iostream>

constexpr int MAX_NMH = 100000;
constexpr long long MAX_P = 1000000000;

int N, M, H, P;
int A[MAX_NMH];

int main(){

	std::cin >> N >> M >> H >> P;

	for(int i = 0; i < N; ++i){
		std::cin >> A[i];
	}

	long long K = 0;

	while(true){

		int tmp = A[K % N];
		if(K != 0 && K % H == 0){
			tmp += M;
		}

		if(P - tmp > 0){
			P -= tmp;
		}
		else{
			break;
		}

		++K;
	}

	std::cout << K << std::endl;

	return 0;
}
