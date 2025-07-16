#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll GCD(ll a, ll b) {
  return a % b ? GCD(b, a % b): b;
}


vector<pair<ll, ll> > prime_factorize(ll n) {
    vector<pair<ll,ll>> res;
    for (ll a = 2; a * a <= n; ++a) {
        if (n % a != 0) continue;
        ll ex = 0; // 指数

        // 割れる限り割り続ける
        while (n % a == 0) {
            ++ex;
            n /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (n != 1) res.push_back({n, 1});
    return res;
}

int main() {
  ll A, B;
  cin >> A >> B;
  
  ll g = GCD(max(A, B), min(A,B));
  
  
  vector<pair<ll,ll>> vec_f = prime_factorize(g);
  
  cout << vec_f.size() + 1 << endl;
  
  
  
  
  
}