#include <bits/stdc++.h>
#define SIZE 300005
#define MOD 1000000007LL
#define INF 1 << 30
#define LLINF 1LL << 60
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DOWN(i,b,a) for(int i=b;i>=a;i--)
#define SET(a,c) memset(a,c,sizeof a)
#define FORALL(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FOREACH(i,c) for(auto (i) : (c))
#define BIT(i,j) ((i)>>(j))&1
#define ALL(o) (o).begin(), (o).end()
#define ERASE(o) (o).erase(unique((o).begin(),(o).end()), (o).end())
#define SQ(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef valarray<int> Array;
typedef pair<ll,ll> Pll;
typedef pair<int, int> Pii;
typedef pair<double, double> Pdd;
template<typename T> inline void priv(vector<T>a){REP(i,a.size()){cout<<a[i]<<((i==a.size()-1)?"\n":" ");}}
ll gcd(ll a,ll b){int c=max(a,b);int d=min(a,b);return c==0||d==0?c:gcd(c%d,d);}
ll lcm(ll a,ll b){return a==0||b==0?0:a*b/gcd(a,b);}

int a[144];

void flip(int x, int y)
{
  if(x>11||y>11||x<0||y<0) return;
  if(a[x+y*12])
  {
    a[x+y*12] = 0;
    flip(x+1,y);
    flip(x-1,y);
    flip(x,y+1);
    flip(x,y-1);
  }
}

void solve()
{
  int cnt = 0;
  REP(i,144) if(a[i])
  {
    cnt++;
    flip(i%12,i/12);
  }
  cout << cnt << endl;
}

int main()
{
  string s;
  int i = 0;
  while(cin >> s)
  {
    REP(j,12) a[i*12+j] = s[j]-'0';
    i=(++i)%12;
    if(i==0) solve();
  }
  return 0;
}