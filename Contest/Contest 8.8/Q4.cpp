#include <iostream>

constexpr int MAX = 10000;

int N, M, K;

struct operation{
	char c;
	int a, b;
};

int main(){
	std::cin >> N >> M >> K;

	int member[MAX];
	operation input[MAX];

	for(int i = 0; i < M; ++i){
		std::cin >> input[i].c >> input[i].a >> input[i].b;
	}

	int max_num = 0;
	for(int i = 0; i < M; ++i){
		if(input[i].c == 'L'){
			int a = input[i].a, b = input[i].b;
			if(member[a] == 0 && member[b] == 0){
				++max_num;
				member[a] = member[b] = max_num;
			}
			else if(member[a] == 0){
				member[a] = member[b];
			}
			else if(member[b] == 0){
				member[b] = member[a];
			}
			else{
				int tmp = member[b];
				member[b] = member[a];
				for(auto &x : member){
					if(x == tmp){
						x = member[a];
					}
				}
			}
		}
	}

	for(int i = 0; i < M; ++i){
		if(input[i].c == 'H'){
			int a = input[i].a, b = input[i].b;
			if(member[a] == 0 && member[b] == 0){
				++max_num;
				member[a] = max_num;
				++max_num;
				member[b] = max_num;
			}
			else if(member[a] == 0){
				++max_num;
				member[a] = max_num;
			}
			else if(member[b] == 0){
				++max_num;
				member[b] = max_num;
			}
		}
	}

	for(int i = 0; i < K; ++i){
		int a, b;
		std::cin >> a >> b;

		if(member[a] == 0 || member[b] == 0){
			puts("unknown");
		}
		else if(member[a] != member[b]){
			puts("different");
		}
		else{
			puts("same");
		}
	}

	return 0;
}
