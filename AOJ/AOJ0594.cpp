#include <cstdio>
#include <algorithm>
#include <cmath>

int W, H, N;
int ans = 0;

int main(){
	scanf("%d%d%d", &W, &H, &N);
	
	int tmp_w, tmp_h;
	for(int i = 0; i < N; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		if(i == 0){
			tmp_w = x, tmp_h = y;
			continue;
		}

		int w_diff = tmp_w - x, h_diff = tmp_h - y;

		if(w_diff > 0 && h_diff > 0){
			ans += std::max(w_diff, h_diff);
		}
		else if(w_diff < 0 && h_diff < 0){
			ans += std::max(-w_diff, -h_diff);
		}
		else{
			ans += abs(w_diff) + abs(h_diff);
		}

		tmp_w = x, tmp_h = y;
	}

	printf("%d\n", ans);

	return 0;
}
