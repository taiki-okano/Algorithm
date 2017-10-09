#include <iostream>
#include <string>
using namespace std;

void func(string str, int n){
    if(n == 0) cout << str << endl;
    
    else{
        func(str + 'a', n - 1);
        func(str + 'b', n - 1);
        func(str + 'c', n - 1);
    }
    
    return;
}

int main(){
    int n;
    
    cin >> n;
    
    
    return 0;
}