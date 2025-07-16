#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;

//階乗関数　ATCODER_AMARIに注意
ll factorial(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    //sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  ll n,q;
  cin >> n >> q;
  string s; 
  cin >> s;

  ll count = 0;
  vector<ll> front(n,0);

  rep(i,s.size()) {
    if(i == 0 ) continue;

    if(s.at(i - 1) == 'A' && s.at(i) == 'C') {
      count++;
    }

    front.at(i) = count;
  }

  ll ans;
  
  rep(i,q) {
    ll l,r;
    cin >> l >> r;
    l--;
    r--;

    ans = front.at(r) - front.at(l);

    cout << ans << endl;
    
  }

  
}
