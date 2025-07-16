#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    rep(i,h) rep(j, w) cin >> s[i][j];
    rep(i,h)rep(j,w){
        if(s[i][j] == '#' && i != 0 && j != 0 && i != h-1 && j != w-1){
            if(s[i+1][j] != '#' && s[i-1][j] != '#' && s[i][j-1] != '#' && s[i][j+1] != '#'){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}