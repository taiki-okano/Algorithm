#include<stdio.h>
#include<time.h>

int scD[18];
clock_t scStartTime,scEndTime;
void scInput(){
	int i;
	for(i=0;i<18;++i)scanf("%d",&scD[i]);
	scStartTime=clock();
}
void scOutput(int s){
	scEndTime=clock();
	printf("Ans= %d, time=%d\n",s,(int)(scEndTime-scStartTime));
}
