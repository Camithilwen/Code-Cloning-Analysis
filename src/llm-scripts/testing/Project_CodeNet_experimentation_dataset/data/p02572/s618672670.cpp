#include <bits/stdc++.h>

using namespace std;

#define Fast  ios::sync_with_stdio(false); cin.tie(0)
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define S second
#define F first
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 5;
ll inf = 1e18;

ll a[N];
ll sm[N];

int main(){

    Fast;

    ll n;
    cin >> n;

    for(int i = 0  ;i < n ;i ++)cin >> a[i];

    sm[n-1] = a[n-1];

    for(int i = n-2; i >= 0 ; i --){
        sm[i] = a[i] + sm[i+1];
        sm[i] %= mod;
    }

    ll ans = 0;

    for(int i = 0 ; i < n-1 ;i ++){
        ans += a[i] * sm[i+1];
        ans %= mod;
    }

    cout << ans ;



    return 0;
}
