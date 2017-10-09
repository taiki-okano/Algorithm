#include <iostream>

constexpr int G = 1, P = 2, T = 4, I = 8;

int n;

int main(){
    std::cin >> n;
    bool flag[4] = {false};
    
    int bit = 0;
    for(int i = 0; i < n - 1; ++i){
        char in;
        std::cin >> in;
        if(in == 'G' && flag[0] == false) bit += G, flag[0] = true;
        else if(in == 'P' && flag[1] == false) bit += P, flag[1] = true;
        else if(in == 'T' && flag[2] == false) bit += T, flag[2] = true;
        else if(in == 'I' && flag[3] == false) bit += I, flag[3] = true;
    }

    bool f = false;
    if(bit == 5 || bit == 4){
        std::cout << 'G';
        f = true;
    }
    if(bit == 1 || bit == 8 || bit == 9 || bit == 3 || bit == 10 || bit == 11){
        if(f)
            std::cout << ' ';
        std::cout << 'P';
        f = true;
    }
    if(bit == 2 || bit == 6){
        if(f)
            std::cout << ' ';
        std::cout << 'T';
        f = true;
    }
    if(bit == 1 || bit == 4 || bit == 5 || bit == 9 || bit == 12 || bit == 13){
        if(f)
            std::cout << ' ';
        std::cout << 'I';
        f = true;
    }
    if(!f)
        std::cout << "No";
    std::cout << std::endl;
    
    return 0;
}
