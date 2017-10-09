#include <iostream>
#include <vector>
#include <string>

int main(){
	std::vector<std::wstring> vec;
	int n;
	std::cin >> n;
	vec.resize(n);
	for(int i = 0; i < n; ++i){
		while(true){
			wchar_t input;
			std::wcin >> input;
			if(input == L'\n'){
				break;
			}
			if(input >= L'あ' && input <= L'ん'){
				vec[i] += input;
			}
			else{
				--i;
				break;
			}
		}
	}
	std::sort(vec.begin(), vec.end());
	for(auto& x : vec){
		std::wcout << x << std::endl;
	}
	return 0;
}
