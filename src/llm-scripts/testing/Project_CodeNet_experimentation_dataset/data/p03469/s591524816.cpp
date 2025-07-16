#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    string ans;
    rep(i, s.length()){
        if(i == 3) ans += '8';
        else ans += s[i];
    }
    cout << ans << endl;
    return 0;
}