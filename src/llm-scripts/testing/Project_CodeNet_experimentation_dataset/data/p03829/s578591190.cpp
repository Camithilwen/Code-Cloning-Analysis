#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;

int main() {
    ll n,a,b;
    cin>>n>>a>>b;
    ll ans=0;
    ll x[n];
    rep(i,n){
        cin>>x[i];
    }
    rep(i,n-1){
        if ((x[i+1]-x[i])*a>b){
            ans+=b;
        }
        else{
            ans+=(x[i+1]-x[i])*a;
        }
    }
    cout<<ans<<endl;
    

    return 0;
}