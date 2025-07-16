#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
int main(void)
{
    ll n, m;
    cin >> n >> m;
    vector<ll> s(m),c(m);
    rep(i,m) cin >> s[i] >> c[i];
    rep(i,1000){
        string t = to_string(i);
        if(t.size()==n){
            bool ok=true;
            rep(j,m){
                if(t[s[j]-1] != c[j]+'0') ok = false;
            }
            if(ok){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}