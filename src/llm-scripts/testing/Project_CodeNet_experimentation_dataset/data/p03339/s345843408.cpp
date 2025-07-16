#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define    ss   second
#define    ff   first
#define    pb   push_back
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);

ll e[mx], w[mx];
int main() {
    FIO;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if(s[i] == 'W') {
            cnt++;
        }
        w[i+1] = cnt;
    }

     cnt = 0;
    for (ll i = n - 1; i >= 0; i--) {
        if(s[i] == 'E') {
            cnt++;
        }
        e[i+1] = cnt;
    }


    ll ans = INT_MAX;
    for (ll i = 1; i <= n; i++) {
        ans = min(ans, w[i-1]+e[i+1]);
    }

    cout << ans << endl;
}
