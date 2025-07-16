#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    ll a=1,b;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            a=i;
        }
    }
    b=n/a;
    ll ans=0;
    while(b>0){
        ans++;
        b/=10;
    }
    cout << ans << endl;
}