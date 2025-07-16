#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int x = tx-sx, y = ty-sy;
    rep(i,x) cout << 'R';
    rep(i,y) cout << 'U';
    rep(i,x) cout << 'L';
    rep(i,y) cout << 'D';
    cout << 'D';
    rep(i,x+1) cout << 'R';
    rep(i,y+1) cout << 'U';
    cout << 'L';
    cout << 'U';
    rep(i,x+1) cout << 'L';
    rep(i,y+1) cout << 'D';
    cout << 'R';
    return 0;
}