#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, k;

int main(void){
    cin >> n >> k;
    vector<bool> r(10);
    rep(i, k){
        lli d;
        cin >> d;
        r[d] = true;
    }
    for(int i = n; i <= 10*n; i++){
        string s = to_string(i);
        bool ok = true;
        rep(j, s.size()){
            if(r[s[j]-'0']) ok = false;
        }
        if(ok){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
