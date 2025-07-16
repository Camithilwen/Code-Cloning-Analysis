// Aaradhya Beri
#pragma GCC optimze("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
#define w(x) int x; cin>>x; while(x--)
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

int powm(int a, int b) {
    int res=1;
    while(b) {
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
 

signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cout<<fixed<<setprecision(8);
    ll x;cin>>x;
   ll res=(x%11<=6)? ((x%11==0)? (x/11)*2:(x/11)*2+1):(x/11)*2+2;
   cout<<res<<endl;
    return 0;
}