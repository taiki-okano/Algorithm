#include <iostream>
#include <cstring>

constexpr int MAX_X = 4, MAX_YN = 50, MAX_Z = 49;

struct mass_data{
    int dx, money;
};

int x, y, z, max_score;
int roulette[MAX_X];
mass_data mass[MAX_YN];

void solve();

int main(){
    while(true){
        std::cin >> x >> y >> z;
        
        if(!x && !y && !z){
            break;
        }

        for(int i = 0; i < x; ++i){
            std::cin >> roulette[i];
        }
        
        max_score = 0;

        for(int i = 0; i < MAX_YN; ++i){
            mass[i].dx  = 0;
            mass[i].money = 0;
        }

        for(int i = 0; i < z; ++i){
            int n, e, a;
            std::cin >> n >> e >> a;
        
            if(e == 1){
                mass[n].dx += a;
            }
            else if(e == 2){
                mass[n].money += a;
            }
            else if(e == 3){
                mass[n].money -= a;
            }
        }

        solve();
    }

    return 0;
}

void solve(){
    int dp[MAX_YN][MAX_YN * 100];
    
    for(int i = 0; i < MAX_YN; ++i){
        for(int j = 0; j <= MAX_YN * 100; ++j){
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for(int i = 0; i < y; ++i){
        for(int j = 0; j <= 5000; ++j){

            int ni, nj;
            for(int k = 0; k < x; ++k){

                ni = std::min(i + roulette[k], y);
                nj = std::max(mass[i].money + j, 0);
                ni = std::min(ni + mass[i].dx, y);
                
                dp[ni][nj] += dp[i][j] * (1 / x);
                /*
                if((ni == y && nj == 5000) || ((ni == 1 || ni == 0) && nj == 5000)){
                    std::cout << "~~~DEBUG~~~" << std::endl;
                    std::cout << "ni : " << ni << std::endl;
                    std::cout << "nj : " << nj << std::endl;
                    std::cout << "i : " << i << std::endl;
                    std::cout << "j : " << j << std::endl;
                    std::cout << "dp[i][j] : " << dp[i][j] << std::endl;
                    std::cout << "money : " << mass[i].money << std::endl;
                    std::cout << "dx : " << mass[i].dx << std::endl;
                    std::cout << "~~DEBUG END~~" << std::endl;
                }
                */
            }
        }
    }

    int sum = 0;
    for(int i = 0; i <= 5000; ++i){
        sum += dp[y][i] * i;
    }

    std::cout << sum << std::endl;
}

