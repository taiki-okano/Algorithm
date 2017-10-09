#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

constexpr int MAX_N = 200;
constexpr int MAX_R = 8;
constexpr int INF = 100000 * MAX_N;

int N, M, R;
int costs[MAX_N][MAX_N] = {};
std::vector<int> order;

int main(){

    std::cin >> N >> M >> R;

    for(int i = 0; i < R; ++i){
        int input;
        std::cin >> input;
        order.push_back(input - 1);
    }

    std::sort(order.begin(), order.end());

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            costs[i][j] = INF;
        }
        costs[i][i] = 0;
    }

    for(int i = 0; i < M; ++i){
        int a, b, c;
        std::cin >> a >> b >> c;
        --a, --b;
        costs[a][b] = std::min(c, costs[a][b]);
        costs[b][a] = std::min(c, costs[b][a]);
    }

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < N; ++k){
                costs[j][k] = std::min(costs[j][k], costs[j][i] + costs[i][k]);
            }
        }
    }

    int ans = INF;
    do{
        int sum = 0;
        for(int i = 1; i < R; ++i){
            sum += costs[order[i]][order[i - 1]];
        }

        ans = std::min(ans, sum);
    } while(std::next_permutation(order.begin(), order.end()));

    std::cout << ans << std::endl;

    return 0;
}
