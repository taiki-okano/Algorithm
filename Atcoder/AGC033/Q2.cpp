#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int H, W, N;
int sr, sc;
std::string S, T;

int main(){
	int aP[4] = {}; //L, U, R, D
	int bP[4] = {};
	int mP[4];

	std::map<char, int> cton;
	cton['L'] = 0, cton['R'] = 2, cton['U'] = 1, cton['D'] = 3;

	std::cin >> H >> W >> N;
	std::cin >> sr >> sc;

	mP[0] = sc - 1, mP[2] = W - sc, mP[1] = sr - 1, mP[3] = H - sr;

	std::cin >> S >> T;

	int n = 0;
	int bdir, brdir;
	while(N--){
		if(n != 0){
			bP[bdir] = std::min(bP[bdir] + 1, mP[bdir] + aP[brdir]);
		}
		int dir = cton[S[n]];
		int rdir = (dir + 2) % 4;
		++aP[dir];
		if(aP[dir] - bP[rdir] > mP[dir]){
			std::cout << "NO" << std::endl;
			return 0;
		}
		bdir = cton[T[n]];
		brdir = (bdir + 2) % 4;
		++n;
	}

	std::cout << "YES" << std::endl;

	return 0;
}
