#include <iostream>
#include <cstring>

constexpr int MAX_X = 1000000, MAX_N = 30;

int value[MAX_N], n, x;
bool dp[MAX_X + 1];
bool is_prime_number[MAX_X + 1];

void initialize();

void solve();

int main(){
    initialize();

    while(true){
        std::cin >> n >> x;
        if(n == 0 && x == 0){
            break;
        }
        
        memset(dp, false, x + 1);

        dp[0] = true;

        for(int i = 0; i < n; ++i){
            std::cin >> value[i];
            dp[value[i]] = true;
        }

        solve();
    }
    return 0;
}

void solve(){
    int ans = 0;

    for(int i = 2; i < x + 1; ++i){
        for(int j = 0; j < n; ++j){
            if(i >= value[j]){
                if(dp[i - value[j]]){
                    dp[i] = true;

                    if(is_prime_number[i]){
                        ans = std::max(ans, i);
                    }

                    break;
                }
            }
        }
    }

    if(ans){
        std::cout << ans << std::endl;
    }
    else{
        std::cout << "NA" << std::endl;
    }
}

void initialize(){
    memset(is_prime_number, true, MAX_X + 1);

    is_prime_number[0] = false, is_prime_number[1] = false;
    for(int i = 2; i * i < MAX_X + 1; ++i){
        if(is_prime_number[i]){
            for(int j = 2; i * j < MAX_X + 1; ++j){
                is_prime_number[i * j] = false;
            }
        }
    }
}
