#include <iostream>
using namespace std;

const int MAX_NM = 100;

int main(){
    int N, M, scores[MAX_NM], targets[MAX_NM], in;

    cin >> N >> M;

    for(int i = 0; i < M; ++i)
        cin >> targets[i];
    
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            cin >> in;
            if(in == targets[i])
                ++scores[j];
            else
                ++scores[targets[i] - 1];
        }
    }

    for(int i = 0; i < N; ++i)
        cout << scores[i] << endl;

    return 0;
}
