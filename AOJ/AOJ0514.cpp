#include <cstdio>
#include <vector>

constexpr int MAX_N = 1000;
constexpr int MAX_ABC = 300;

struct pair{
	int a, b, c;
	pair(int _a, int _b, int _c) : a(_a), b(_b), c(_c){};
};

int main(){
	while(true){
		int A, B, C, N;
		int status[MAX_ABC];

		scanf("%d%d%d", &A, &B, &C);

		if(A == 0 && B == 0 && C == 0){
			break;
		}

		scanf("%d", &N);

		std::vector<pair> pairs;
		for(int i = 0; i < N; ++i){
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			--a;

			if(d == 1){
				status[a] = status[a + b] = status[a + b + c] = 1;
			}
			else{
				pairs.push_back(pair(a, a + b, a + b + c));
			}
		}

		for(auto& x : pairs){
			int tmp = status[x.a] + status[x.b] + status[x.c];
			if(tmp == 2){
				if(status[x.a] < 1){
					status[x.a] = -1;
				}
				if(status[x.b] < 1){
					status[x.b] = -1;
				}
				if(status[x.c] < 1){
					status[x.c] = -1;
				}
			}
		}

		for(int i = 0; i < A + B + C; ++i){
			if(status[i] == -1){
				status[i] = 0;
			}
			else if(status[i] == 0){
				status[i] = 2;
			}
			printf("%d\n", status[i]);
		}
	}
	return 0;
}
