#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    int max_x;
    cin >> max_x;
    rep(i, N - 1){
        int x;
        cin >> x;
        max_x = max(max_x, x);
    }
    int min_y;
    cin >> min_y;
    rep(i, N - 1){
        int y;
        cin >> y;
        min_y = min(min_y, y);
    }
    for (int i = X + 1; i <= Y; i++){
        if (max_x < i && i <= min_y){
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
}
