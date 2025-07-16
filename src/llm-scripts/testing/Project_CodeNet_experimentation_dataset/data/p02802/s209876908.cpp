#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mtv(kit) cout<<#kit<<" - "<<kit<<"\n";
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map

void doit(){
    ll n,q,i,a1 = 0, a2 = 0;
    ump<ll, ll>mpAC,mpWA;
    string s;
    cin >> n >> q;
    while(q--){
        ll k;
        cin >> k >> s;
        if(s == "WA"){
            if(mpAC.find(k) == mpAC.end())mpWA[k]++;
        }
        else {
            if(mpAC.find(k) == mpAC.end()){
                a2 += mpWA[k];
                a1++;
            }
            mpAC[k] = 1;
        }
    }
    cout << a1 << " " << a2 << nl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}
