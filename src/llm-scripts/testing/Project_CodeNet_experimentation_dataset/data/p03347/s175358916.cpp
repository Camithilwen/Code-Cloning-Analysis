#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

void prvec(vector<ll> vec){
    ll n = vec.size();
    rep(i,n) cout << "i" << " " << vec.at(i) << "\n";
}

void pr2d(vector<vector<ll>> vvec){
    ll h = vvec.size();
    ll w = vvec.at(0).size();
    rep(i,h){
        rep(j,w){
            cout << vvec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
}

int main(){
    ll n ; cin >> n;
    ll prev ; cin >> prev;
    bool NG = false;
    if(prev!=0) NG = true;
    ll ans = 0;
    rep(i,n-1){
        ll x ; cin >> x;
        if(x == prev + 1){
            ans++;
        }else if(x>prev+1){
            NG = true;
        }else{
            ans+=x;
        }
        prev = x;
    }
    if(NG){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}