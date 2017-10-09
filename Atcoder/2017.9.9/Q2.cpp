#include <iostream>

int main(){

  int n;

  std::cin >> n;

  int sum = 0;

  for(int i = 0; i < n; ++i){
    int l, r;
    std::cin >> l >> r;
    sum += r - l + 1;
  }

  std::cout << sum << std::endl;

  return 0;
}
