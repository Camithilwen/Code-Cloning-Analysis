#include "bits/stdc++.h"

#define MOD 1000000007
#define rep(i, n) for(ll i=0; i < (n); i++)
#define rrep(i, n) for(ll i=(n)-1; i >=0; i--)
#define ALL(v) v.begin(),v.end()
#define rALL(v) v.rbegin(),v.rend()
#define FOR(i, j, k) for(ll i=j;i<k;i++)
#define DUMP(i, v)for(ll i=0;i<v.size();i++)cerr<<v[i]<<" "

using namespace std;
typedef long long int ll;
typedef vector<ll> llvec;
typedef vector<double> dvec;
typedef pair<ll, ll> P;
typedef long double ld;
struct edge{ll x, c;};

ll mod(ll a, ll mod){
  ll res = a%mod;
  while(res<0)res=res + mod;
  return res;
}

ll modpow(ll a, ll n, ll mod){
  ll res=1;
  while(n>0){
    if(n&1) res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll modinv(ll a, ll mod){
  return modpow(a, mod-2, mod);
}

ll gcd(ll a, ll b){
  ll r = a%b;
  if(r==0) return b;
  else return gcd(b, a%b);
}

bool is_prime(ll n){
  ll i = 2;
  if(n==1)return false;
  if(n==2)return true;
  bool res = true;
  while(i*i <n){
    if(n%i==0){
      res = false;
    }
    i = i+1;
  }

  //if(i==1)res = false;
  if(n%i==0)res=false;
  return res;
}

struct UnionFind{
  ll N;
  llvec p;
  llvec cnt;
  UnionFind(ll n){
    N = n;
    p=llvec(N);
    cnt=llvec(N, 0);
    rep(i, N){
      p[i] = i;
      cnt[i] = 1;
    }
  }

  void con(ll a, ll b){
    P at = root(a);
    P bt = root(b);
    if(at.second!=bt.second){
      if(at.first>bt.first){
        swap(at, bt);
        swap(a, b);
      }
      p[at.second] = bt.second;
      cnt[bt.second]+=cnt[at.second];
      p[a]=bt.second;
    }
  }

  P root(ll a){
    ll atmp = a;
    ll c=0;
    while(atmp!=p[atmp]){
      atmp = p[atmp];
      c++;
    }
    p[a] = atmp;
    return {c, atmp};
  }

  bool is_con(ll a, ll b){
    P at=root(a);
    P bt=root(b);
    return at.second == bt.second;
  }
  
};

struct dijkstra{
  ll N;
  llvec d;
  vector<vector<edge>> e;
  dijkstra(ll n){
    N = n;
    //d = llvec(N, 1e18);
    e = vector<vector<edge>>(N);
  }

  void add_edge(ll from, ll to, ll cost){
    e[from].push_back({to, cost});
  }

  void run(ll start){
    priority_queue<P, vector<P>, greater<P>> que;
    que.push({0, start});
    d = llvec(N, 1e18);
    d[start]=0;
    while(!que.empty()){
      P q = que.top();que.pop();
      ll dc = q.first;
      ll x = q.second;
      if(dc>d[x]){
        continue;
      }else{
        for(auto ip: e[x]){
          if(d[ip.x]<=d[x]+ip.c){
            continue;
          }else{
            d[ip.x]= d[x]+ip.c;
            que.push({d[ip.x], ip.x});
          }
        }
      }
    }
  }  
};

ll fact[500000];
ll ifact[500000];

void gen(){
  fact[0]=ifact[0]=1;
  rep(i, 200100){
    fact[i+1]=mod(fact[i]*(i+1), MOD);
    ifact[i+1]=modinv(fact[i+1], MOD);
  }
}

ll comb(ll n, ll k){
  return mod(mod(fact[n]*ifact[n-k], MOD)*ifact[k], MOD);
}

/**************************************
** A main function starts from here  **
***************************************/
int main(){
  ll N, M, K;
  cin >> N >> M >> K;
  ll ans = 0;
  gen();
  rep(i, N*M){
    ll x = i/N+1;
    ll y = i/M+1;
    ans =mod(ans+ (M-x)*(M-x+1)/2*N, MOD);
    ans =mod(ans+ (N-y)*(N-y+1)/2*M, MOD);
  }
  cout << mod(ans*comb(N*M-2, K-2),MOD)<<endl;
  return 0;
}
