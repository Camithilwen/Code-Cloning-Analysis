#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}
const ll MOD = 1e9+7;
long long Comb(int n, int i){long long ans = 1; if(i>n || i < 0) return 0; if(i == 0 || i == n) return 1; else {for(int j = 1; j <= i; ++j){
      ans *=(n+1-j);
      ans /= j;
      ans %= MOD;} }return ans;}

template<typename T> T gcd(T a, T b){if(b == 0) return a;else return gcd(b, a%b);}
template<typename T> T lcm(T a, T b){if(b > a) swap(a, b); T g = gcd(a, b);return a / g * b;
}


void solve() {
    int n; cin >> n;
    map<ll,ll, greater<ll>> mp;
    rep(i, n) {
        ll tmp;
        cin >> tmp;
        mp[tmp]++;
    }
    int cnt = 0;
    ll ans = 1;
    for(auto p: mp){
        if(p.second >= 4 && cnt == 0) {
            ans = p.first * p.first;
            cnt = 2;
            break;
        } else if (p.second >= 2 && cnt == 1) {
            ans *= p.first;
            cnt++;
            break;
        } else if(p.second >= 2 && cnt == 0) {
            ans *= p.first;
            cnt++;
        }
    }
    if(cnt <= 1) cout << 0 << endl;
    else cout << ans << endl;
}

int main(void){
  solve();
  return 0; 
}
