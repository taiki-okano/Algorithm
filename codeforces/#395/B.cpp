#include <cstdio>
#include <vector>

void swap(int& a, int& b){
    int& tmp = a;
    a = b;
    b = tmp;
}

int main(){
	int n;
	scanf("%d", &n);
	std::vector<int> a(n);

	for(auto& x : a){
		scanf("%d", &x);
	}

	for(int i = 0; i < n / 2; ++i){
		if(i % 2 == 0){
		    swap(a[i], a[n - i - 1]);
        }
	}
    
    
    for(int i = 0; i < n; ++i){
        if(i == n - 1){
            printf("%d", a[i]);
        }
        else{
            printf("%d ", a[i]);
        }
    }
    
	return 0;
}
