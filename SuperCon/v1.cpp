#include<stdio.h>
#include<algorithm>
#include"sc1.h"

const int dx[]={1, 0, -1, 0};
const int dy[]={0, 1, 0, -1};

bool map[1001][1001]; //原点(500,500)
int ans;

//全探索(DFS)
void solve(int x, int y, int count){
    //枝切り(距離から考えて戻ってこれないものを削除)
    int dis=std::abs(x-500)+std::abs(y-500);
    if(dis>scN-count)return;
	
	//原点に移動したとき
	if(x==500&&y==500&&count>0){
		if(count==scN){
			++ans;
			return;
		}//最後に到達した
		else{
			return;
		}//早く移動してしまった
	}	

    for(int i=0; i<4; ++i){
        int rx=x+dx[i];
        int ry=y+dy[i];
        if(!map[rx][ry]){
            map[rx][ry]=true;
            solve(rx,ry,count+1);
            map[rx][ry]=false;                
        }
    }

}

int main(){
    scInput();
    //障害物設置
    for(int i=0;i<scM;i++){
        map[scB[0][i]+500][scB[1][i]+500]=true;
    }
    solve(500,500,0);
    scOutput(ans);
    return 0;
}
