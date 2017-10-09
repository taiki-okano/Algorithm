#include <iostream>

#define MAX_HW 100

int h, w;
bool cloud[MAX_HW][MAX_HW * 2] = {false};
int ans [MAX_HW][MAX_HW];

void solve();

int main(){
	std::cin >> h >> w;
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++i){
			ans[i][j] = -1;
			char in;
			std::cin >> in;
			if(in == 'c')
				cloud[i][j] = true;
		}
	}
	for(int i = 0; i < w; ++i){
		for(int j = 0; j < h; ++j){
			for(int k = w - 1; k >= 0; --k){
				if(cloud[j][k] && ans[j][k] == -1){
					ans[j][k] = i;
					cloud[j][k + 1] = true;
					cloud[j][k] = false;
				}
			}
		}
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j)
			std::cout << ans[i][j];
	}

	return 0;
}