#include <iostream>
#include <string>
using namespace std;

int func(int n){
    int count = 0;
    
    string str = to_string(n);
    
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '1')
            ++count;
    }
    
    return count;
}
 
int main(){
    int n;
    cin >> n;
    
    int count = 0;
    for(int i = 1; i <= n; ++i){
        count += func(i);
    }
    
    cout << count << endl;
    return 0;
}