#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int a, b;
    cin >> a >> b;

    vector<string> ans(100, "");
    for(int i = 0; i < 50; i++) {
        rep(j, 100) ans[i] += "#";
    }
    for(int i = 50; i < 100; i++) {
        rep(j, 100) ans[i] += '.';
    }
    
    a--;
    b--;

    for(int i = 1; i < 50; i += 2){
        if(a == 0) break;
        for(int j = 1; j < 100; j += 2){
            if(a == 0) break;
            ans[i][j] = '.';
            a--;
        }
    }
    for(int i = 51; i < 100; i += 2){
        if(b == 0) break;
        for(int j = 1; j < 100; j += 2){
            if(b == 0) break;
            ans[i][j] = '#';
            b--;
        }
    }
    cout << "100 100" << endl;
    rep(i, 100) cout << ans[i] << endl;
}