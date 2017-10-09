#include <iostream>

int N,sum=0;

bool solve(int a){
	for(int i=2;i<a;++i){
		if(a%i==0)
			return false;
	}
	return true;
}

int main(){
	int x;
	std::cin>>N;
	int sum = 0;
	for(int i=0;i<N;++i){
		std::cin>>x;
		
		if(x!=1&&solve(x))
			sum+=1;
	}
	std::cout<<sum<<std::endl;
	return 0;
}