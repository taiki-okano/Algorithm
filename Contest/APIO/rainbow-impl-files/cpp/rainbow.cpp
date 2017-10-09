#include "rainbow.h"

#include <cstdio>
#include <cstring>

constexpr int MAX_HW = 1000;
constexpr int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int H, W;
int sh, sw, eh, ew;
char str[100000 + 6];
bool river[MAX_HW][MAX_HW];

void dfs(int h, int w){
	river[h][w] = true;
	for(int i = 0; i < 4; ++i){
		int nh = h + dx[i], nw = w + dy[i];
		if(nh >= sh && nw >= sw && nh <= eh && nw <= ew && !river[nh][nw]){
			dfs(nh, nw);
		}
	}
}

void init(int R, int C, int sr, int sc, int M, char *S) {
	H = R, W = C;
	strcpy(str, S);

	--sr, --sc;
	river[sr][sc] = true;

	printf("DEBUG : strlen(str) = %d\n", strlen(str));
	/*
	for(int i = 0; i < strlen(str); ++i){
		if(str[i] == 'N'){
			--sr;
		}
		else if(str[i] == 'E'){
			++sc;
		}
		else if(str[i] == 'S'){
			++sr;
		}
		else if(str[i] == 'W'){
			--sc;
		}
		river[sr][sc] = true;
	}
	*/
}

int colour(int ar, int ac, int br, int bc) {
	--ar, --ac, --br, --bc;
	sh = ar, sw = ac, eh = br, ew = bc;

	int ans = 0;
	for(int i = sh; i <= eh; ++i){
		for(int j = sw; eh <= ew; ++j){
			if(!river[i][j]){
				++ans;
				dfs(i, j);
			}
		}
	}

 	return ans;
}

