#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ll n;
    cin >> n;
    ll ans = mod;
    for(ll i = 1; i*i <= n; i++){
        if(n%i == 0){
            ll a = to_string(n/i).size();
            ll b = to_string(i).size();
            ans = min(ans,max(a,b));
        }
    }
    cout << ans << endl;
    return 0;
}