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

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

vector<bool> isp;
vector<ll> prime;

void sieve(int x=pow(10,6)+10) {
  isp.resize(x,true); 
  isp[0] = false;
  isp[1] = false;
  for (int i=2; pow(i,2)<=x; i++) {
    if (isp[i]) for(int j=2; i*j<=x; j++) isp[i*j] = false;
  }
  rep(i,x+1) if (isp[i]) prime.push_back(i);
}

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

int main() {
  sieve();
  int N; cin >> N;
  int tn = N%2==0 ? N+1 : N;
  ll result[tn][tn] = {}; rep(i,tn) fill_n(result[i],tn,1);
  rep(i,tn) rep(j,tn) if ((i+j)%2==0) result[i][j] = prime[(i+j)/2] * prime[tn+((tn-1-i)+j)/2];
  rep(i,tn) rep(j,tn) {
    if ((i+j)%2==1) {
      if (i!=0)    result[i][j] = lcm(result[i][j], result[i-1][j]);
      if (i!=tn-1) result[i][j] = lcm(result[i][j], result[i+1][j]);
      if (j!=0)    result[i][j] = lcm(result[i][j], result[i][j-1]);
      if (j!=tn-1) result[i][j] = lcm(result[i][j], result[i][j+1]);
      result[i][j]++;
    }
  }
  // ll r = 0; rep(i,N) rep(j,N) r = max(r, result[i][j]);
  // cout << r << endl;
  rep(i,N) debug(result[i],result[i]+N);
  return 0;
}