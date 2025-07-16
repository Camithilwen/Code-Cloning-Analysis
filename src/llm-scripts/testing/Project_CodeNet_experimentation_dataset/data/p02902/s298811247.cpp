#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpl;
typedef vector<vll> vvll;

#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define REP1(i,n) for(int i=1;i<((int)n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define no cout<<"No"<<endl
#define NO cout<<"NO"<<endl
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

ll pos=-1;
const ll MAX_N=1001;
vector<bool> visited,finished;
vvll edge(MAX_N);
vll hist;

void dfs(ll now){
  visited[now]=true;
  hist.push_back(now);
  for(auto e:edge[now]){
    if(finished[e])
      continue;

    if(visited[e]&&!finished[e]){
      pos=e;
      return;
    }

    dfs(e);
    if(pos!=-1)
      return;
  }

  hist.pop_back();
  finished[now]=true;
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin>>n>>m;
  REP(i,m){
    ll a,b;
    cin>>a>>b;
    a--;
    b--;
    edge[a].push_back(b);
  }

  //find cycle
  visited.assign(n,false);
  finished.assign(n,false);
  pos=-1;
  REP(i,n){
    dfs(i);
    if(pos!=-1)
      break;
  }

  if(pos==-1){
    cout<<-1<<endl;
    return 0;
  }

  //restoration cycle
  vll cycle;
  while(true){
    ll t=hist.back();
    hist.pop_back();
    cycle.push_back(t);
    if(pos==t)
      break;
  }

  reverse(ALL(cycle));

  //minimize
  while(true){
    ll nc=cycle.size();
    vll table(n,-1);
    REP(i,nc)table[cycle[i]]=i;

    ll from=-1,to=-1;
    REP(i,nc){
      for(auto e:edge[cycle[i]]){
        if(table[e]!=(i+1)%nc && table[e]!=-1){
          from=i;
          to=table[e];
        }
      }
    }

    if(from==-1)
      break;

    vll ncycle;
    ll cur=to;
    while(true){
      ncycle.push_back(cycle[cur]);
      cur=(cur+1)%nc;
      if(cur==from)
        break;
    }
    ncycle.push_back(cycle[from]);
    cycle=ncycle;
  }

  cout<<cycle.size()<<endl;
  REP(i,cycle.size())cout<<cycle[i]+1<<endl;
}

