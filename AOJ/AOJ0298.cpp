#include <iostream>
#include <queue>
#include <vector>

typedef std::pair<int, int> P;

int main(){
	std::priority_queue<P, std::vector<P>, std::greater<P> > que;
	int n, m;
	
	std::cin >> n;
	while(n--){
		int hour, min;
		std::cin >> hour >> min;
		que.push(P(hour, min));
	}

	std::cin >> m;
	while(m--){
		int hour, min;
		std::cin >> hour >> min;
		que.push(P(hour, min));
	}

	bool flag = false;
	int lmin = 100, lhour = 100;
	while(!que.empty()){
		P p = que.top(); que.pop();
		if(!(lhour == p.first && lmin == p.second)){
			if(flag)
				std::cout << " ";
			std::cout << p.first << ":";
			if(p.second < 10)
				std::cout << 0;
			std::cout << p.second;
		}
		lhour = p.first;
		lmin = p.second;
		if(que.size() == 0)
			std::cout << std::endl;
		if(!flag)
			flag = true;
	}
	return 0;
}