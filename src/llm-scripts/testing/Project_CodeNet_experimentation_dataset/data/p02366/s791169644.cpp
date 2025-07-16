#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<pair<ll, ll>> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)
#define FI first
#define SE second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define TS to_string
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
#define endl "\n"


ll INF = 1e9;
ll MOD = 1000000007;
ll LINF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "Yes" << endl;}
void no(){ cout << "No" << endl;}

//-----------------------------------------
ll timer;
vll pre, par, low, seen;
vvll graph;

void init(ll N){
  pre.resize(N); par.resize(N);
  low.resize(N); seen.resize(N,0);
  graph.resize(N,vll());
  timer = 1;
}
void dfs(ll cur, ll pas){

  pre[cur] = low[cur] = timer;
  timer++;

  seen[cur] = 1;

  for(ll i=0;i<graph[cur].size();i++){
    ll next = graph[cur][i];
    if(!seen[next]){
      par[next] =  cur;

      dfs(next, cur);
      low[cur] = min(low[cur], low[next]);
    }
    else if(next != pas){
      low[cur] = min(low[cur], pre[next]);
    }
  }
}

void art_point(ll N, set<ll> &arp){
  seen.resize(N,0);
  timer = 1;
  dfs(0,-1);

  ll np = 0;
  for(ll i=1;i<N;i++){
    ll p = par[i];
    if(p == 0) np++;
    else if(pre[p] <= low[i]) arp.insert(p);
  }
  if(np > 1) arp.insert(0);

}
//-----------------------------------------

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll v, e;
  cin >> v >> e;
  init(v);
  REP(i,e){
    ll a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  set<ll> st;
  art_point(v,st);
  IREP(i,st) cout << (*i) <<endl;

  return 0;
}


