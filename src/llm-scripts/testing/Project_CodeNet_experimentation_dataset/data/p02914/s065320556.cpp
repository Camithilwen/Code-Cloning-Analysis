#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define FIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(in) in.begin(), in.end()

ll base[65];

void smallAns(ll x){
    for(ll i = 60 ; i >= 0 ; i--){
        if((x>>i) & 1){
            if(base[i] == 0){
                base[i] = x;    return;
            }
            x ^= base[i];
        }
    }
}

int main(){
    FIO;
    ll n;   cin >> n;
    ll check = 0;
    vector<ll> v;
    for(ll i = 0 ; i < n ; i++){
        ll x;   cin >> x;   v.push_back(x);
        check ^= x;
    }
    for(ll i = 0 ; i < n ; i++){
        v[i] &= (~check);
        smallAns(v[i]);
    }
    ll ans = 0;
    for(ll i = 60 ; i >= 0 ; i--){
        ans = max(ans, ans^base[i]);
    }
    ans = ans + (ans ^ check);
    cout << ans << endl;
    return 0;
}