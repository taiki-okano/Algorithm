#include <iostream>
#include <vector>
#include <string>

int main(){
    int N;
    std::string s;
    std::vector<int> points;

    std::cin >> N >> s;

    int ans = 0;

    points.push_back(0);
    auto last_itr = points.end();
    int zero_counter = 0, one_counter = 0, last_one_pos = 0;
    bool did_last_add = false;
    for(int i = 0; i < s.size() - 2; ++i){
        if(s[i] == '0'){
            ++zero_counter;
            last_one_pos = i + 1;
            one_counter = 0;
        }
        else{
            ++one_counter;
            zero_counter = 0;
        }

        if(s[i] != '1' || s[i + 1] != '0' || s[i + 2] != '1'){
            did_last_add = false;
            continue;
        }

        did_last_add = true;

        int one_counter2 = 0, last_one_pos2;
        for(int j = i + 2; j < s.size() - 2; ++j){
            if(s[j] == '0'){
                last_one_pos2 =
            }
        }
    }
    return 0;
}
