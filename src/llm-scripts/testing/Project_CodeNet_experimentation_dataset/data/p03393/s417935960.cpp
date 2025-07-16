#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long

signed main() {
    string s;
    cin >> s;
    vector<int> a(26);
    int n = s.length();
    rep(i,n) a[(int)(s[i]-'a')]++;
    int id = -1;
    rep(i,26) {
        if(a[i]==0) {
            id=i;
            break;
        }
    }
    if(id!=-1) {
        cout << s+(char)('a'+id) << endl;
        return 0;
    }
    id = (int)(s[n-1]-'a');
    rrep(i,n-1) {
        if(s[i]>s[i+1]) {
            continue;
        }
        char cc = 'z';
        rrep(j,n) {
            if(i==j) break;
            if(s[i]>s[j]) continue;
            else cc = min(cc, s[j]);
        }
        cout << s.substr(0,i)+cc << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}

