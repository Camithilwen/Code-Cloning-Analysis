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
  if(res<0)res=res + mod;
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


/**************************************
** A main function starts from here  **
***************************************/
int main(){
  ll N, M, Q;
  cin >> N >> M >> Q;
  vector<llvec> T(N+1, llvec(N+1, 0));
  vector<llvec> S(N+1, llvec(N+1, 0));
  rep(i, M){
    ll a, b;
    cin >> a >> b;
    T[a][b] += 1;
  }
  FOR(i, 1, N+1){
    FOR(j, 1, N+1){
      S[i][j] = S[i][j-1] + T[i][j];
    }
  }
  FOR(i, 1, N+1){
    FOR(j, 1, N+1){
      S[i][j] += S[i-1][j];
    }
  }

  rep(i, Q){
    ll a, b;
    cin >> a >> b;
    a--;
    cout << S[b][b] - S[a][b] - S[b][a] + S[a][a] << endl;
  }
  
  return 0;
}
