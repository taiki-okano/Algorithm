#include <iostream>
#include <string>
#include <algorithm>

int main(){

    int N;
    std::string s;

    std::cin >> N >> s;

    int ans = 0;

    while(true){
        bool flag = false;
        int t_counter = 0, last = 0;
        bool flag3 = false;
        for(int i = 0; i < s.size() - 2; ++i){
            if(s[i] == '1'){
                ++t_counter;
            }
            else{
                last = i + 1;
                t_counter = 0;
            }
            if(s[i] != '1' || s[i + 1] != '0' || s[i + 2] != '1'){
                continue;
            }

            bool flag2 = false;
            int tmp = 0, front = i + 2;
            for(int j = i + 2; j < s.size(); ++j){
                if(s[j] == '0'){
                    int check_tmp = 0;
                    for(int k = j + 1; k < s.size(); ++k){
                        if(s[k] == '0'){
                            break;
                        }
                        ++check_tmp;
                    }
                    if((check_tmp > t_counter && check_tmp > tmp) || (flag3 && check_tmp > 0)){
                        flag2 = true;
                    }
                    break;
                }
                ++tmp;
                front = j;
            }
            if(flag2){
                flag3 = true;
                continue;
            }
            else{
                flag3 = false;
            }

            if(t_counter == 0 && tmp == 0){
                continue;
            }
            if(t_counter > tmp){
                for(int j = last; j <= i + 2; ++j){
                    s[j] = '0';
                }
                s[last + 1] = '1';
                ans += 1 + std::max(t_counter - 1, 0);
            }
            else{
                for(int j = i; j <= front; ++j){
                    s[j] = '0';
                }
                s[front - 1] = '1';
                ans += 1 + std::max(tmp - 1, 0);
            }
            flag = true;
        }
        if(!flag){
            break;
        }
    }

    while(true){
        bool flag = false;
        for(int i = 0; i < s.size() - 2; ++i){
            if(s[i] != '1' || s[i + 1] != '0' || s[i + 2] != '1'){
                continue;
            }

            ++ans;
            s[i] = '0', s[i + 1] = '1', s[i + 2] = '0';
        }
        if(!flag){
            break;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
