#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        ll d = 0, m = 0, dm = 0, dmc = 0;
        rep(i,n){
            if(i >= k){
                if(s[i-k] == 'D'){ d--; dm -= m; }
                else if(s[i-k] == 'M') m--;
            }
            if(s[i] == 'D') d++;
            else if(s[i] == 'M'){ dm += d; m++; }
            else if(s[i] == 'C') dmc += dm;
        }
        cout << dmc << endl;
    }
    return 0;
}