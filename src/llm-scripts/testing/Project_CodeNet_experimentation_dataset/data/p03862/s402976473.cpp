#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,x;
    cin >> n >> x;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    ll ans=0;
    for(ll i=1;i<n;i++){
        if(a[i-1]+a[i]>x){
            ll k=(a[i]+a[i-1]-x);
            ans+=k;
            a[i]-=k;
            if(a[i]<0) a[i]=0;
        }
    }
    cout << ans << endl;
}