#include<stdio.h>
#include<time.h>

int scP[2];
clock_t scStartTime,scEndTime;
void scInput(){
	scanf("%d%d",&scP[0],&scP[1]);
	scStartTime=clock();
}
void scOutput(int s){
	scEndTime=clock();
	printf("Ans= %d, time=%d\n",s,(int)(scEndTime-scStartTime));
}
