#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using iii = pair<ii, ll>;
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define __lcm(a, b) a * b / __gcd(a, b)
const ll MOD = 1e9 + 7;
const ll INF = 2e9;
// const ll N = ;

ll a, b, temp;

ll factorize(ll x) {
    ll ret = 1;
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            ret++;
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) ret++;
    return ret;
}

void solve() {
    cin >> a >> b;
    temp = __gcd(a, b);
    cout << factorize(temp) << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}