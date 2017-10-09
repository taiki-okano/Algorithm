#include <iostream>

template<class T>
vector<vector<T>> Imos2D(const vector<vector<T>> &a) {
    int h = a.size(), w = a[0].size();
    vector<vector<T>> s(h+1, vector<T>(w+1, 0));
    rep(i, h)rep(j, w) s[i+1][j+1] = a[i][j];
    rep(i, h+1)rep(j, w) s[i][j+1] += s[i][j];
    rep(i, h)rep(j, w+1) s[i+1][j] += s[i][j];
    return s;
}

template<class T>
int sum(const vector<vector<T>>& s, int i, int j, int h, int w) {
    return s[i+h][j+w] - s[i][j+w] - s[i+h][j] + s[i][j];
}

int main(){
    std::vector<std::vector<int>> s;
    int sum
    return 0;
}
