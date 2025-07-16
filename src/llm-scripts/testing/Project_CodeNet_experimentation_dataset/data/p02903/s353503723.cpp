#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    vector<vector<int>> ans(h, vector<int>(w, 0));
    rep(i, h)rep(j, w){
        if((i<b&&j<a) || (i>=b&&j>=a))ans[i][j] = 1;
    }
    rep(i, h){
        rep(j, w)cout << ans[i][j];
        cout << endl;
    }
    
}