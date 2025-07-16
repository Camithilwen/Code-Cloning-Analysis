///FUCKOUT
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
//#define endl '\n'

using ll = long long;
using db = long double;
using row = vector<int>;
using ii = pair<ll, ll>;

#define int ll

const int N = 2e5+5, M = 1e6 + 5, LG = 17, MOD = 1e6 + 3;
const int BLOCK = 55;
const int BLOCKN = N / BLOCK + 1;
const long double EPS = 1e-7;
using ull = unsigned long long;
ll t[N<<2];
ll tA[N<<2], tB[N<<2];
void upd(int node, int s, int e, int idx, ll v){
  t[node] = min(t[node], v);
  tA[node] = min(tA[node], v + idx);
  tB[node] = min(tB[node], v - idx);
  if(s==e)return;
  int md = (s+e)>>1;
  if(idx<=md)
    upd(node<<1,s,md,idx,v);
  else
    upd(node<<1|1,md+1,e,idx,v);
}
ll qry(int node, int s, int e, int idx){
  if(e < idx)return idx + tB[node];
  if(s > idx)return tA[node] - idx;
  if(s==e)return t[node];
  int md = (s+e)>>1;
  return min(qry(node<<1,s,md,idx),qry(node<<1|1,md+1,e,idx));
}
int32_t main(){
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE
  memset(t,63, sizeof t);
  memset(tA,63, sizeof tA);
  memset(tB,63, sizeof tB);
  int n, q, A, B;
  cin >> n >> q >> A >> B;

  upd(1, 1, n, A, 0);

  int prv = B;
  ll ans = 0;
  while(q--){
    int x;
    cin >> x;
    ll val = qry(1, 1, n, x) + ans;
    ans += abs(x - prv);
    upd(1, 1, n, prv, val - ans);
    prv = x;
  }

  cout << ans+t[1]<<'\n';
  return 0;
}
