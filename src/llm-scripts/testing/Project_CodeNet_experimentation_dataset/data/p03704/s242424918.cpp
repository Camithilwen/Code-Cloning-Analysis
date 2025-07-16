#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(int x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { int d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }


int main() {
  ll D; cin >> D;
  ll result = 0;
  rep(dig,19) {
    rep(pm,1<<((dig+1)/2-1)) {
      ll td = D, l = pow(10,dig-1), r = 1;
      bool plus[(dig+1)/2]; rep(i,(dig+1)/2) plus[i] = pm&(1<<i); plus[(dig+1)/2-1] = true;
      ll diff[(dig+1)/2];
      per(i,(dig+1)/2) {
        ll left = (td/r%10+10)%10;
        if (plus[i]) { diff[i] = (10-left)%10; td -= (l-r)*diff[i]; }
        else { diff[i] = left; td += (l-r)*diff[i]; }
        l /= 10; r *= 10;
      }
      bool ok = td==0;
      rep(i,(dig+1)/2-1) { if (diff[i]==0&&plus[i]) ok = false; }
      if (!ok) continue;
      // cout << dig << "," << pm << "->" << td << "..."; debug(diff,diff+(dig+1)/2);
      ll tmpr = 1; rep(i,(dig+1)/2) {
        if (i==0&&dig%2==1) tmpr *= 10;
        else if (i==(dig+1)/2-1) tmpr *= 9-diff[i];
        else tmpr *= 10-diff[i];
      }
      result += tmpr;
    }
  }
  cout << result << endl;
  return 0;
}