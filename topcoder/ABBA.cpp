#include <cstdio>
#include <cstring>
#include <algorithm>

constexpr int MAX_LENGTH_OF_STRING = 1000;

char initial_str[MAX_LENGTH_OF_STRING], target_str[MAX_LENGTH_OF_STRING];

bool function(const char* str, int length);

int main(){
    scanf("%s%s", initial_str, target_str);
    int init_A = 0, init_B = 0;
    for(int i = 0; i < strlen(initial_str); ++i){
        if(initial_str[i] == 'A'){
            ++init_A;
        }
        else{
            ++init_B;
        }
    }
    int tar_A = 0, tar_B = 0;
    for(int i = 0; i < strlen(target_str); ++i){
        if(target_str[i] == 'A'){
            ++tar_A;
        }
        else{
            ++tar_B;
        }
    }
    if(init_A > tar_A){
        puts("Impossible");
        return 0;
    }
    if(init_B > tar_B){
        puts("Impossible");
        return 0;
    }
    
    if(function(initial_str, strlen(initial_str))){
        puts("Possible");
    }
    else{
        puts("Impossible");
    }

    return 0;
}

bool function(const char* str, int length){
    if(!strcmp(str, target_str)){
        return true;
    }
    if(!length){
        return false;
    }
    if(function(&strcat(str, "A"), length - 1)){
        return true;
    }
    if(function(&strcat(std::reverse(str, str + strlen(str)), "B"), length - 1)){
        return true;
    }
    return false;
}
