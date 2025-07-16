#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)
  
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()
  
#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

#define INF 1000000000

typedef long double Real;
#define EPS 1e-11
#define EQ(x) (-EPS<x && x<EPS)
typedef complex<Real> P;
Real dot(P a,P b){return real(conj(a)*b);}
Real cross(P a,P b){return imag(conj(a)*b);}

char s[10];
bool eq(int a,int b,int c,char o){
  return (s[a]==o && s[b]==o && s[c]==o);
}

int mp[12][12];

void dfs(int x,int y,int k){
  if(x<0 || x>=12 || y<0 || y>=12)return;
  if(mp[x][y]!=-1)return;
  mp[x][y] = k;
  int d[5]={0,1,0,-1,0};
  REP(i,4)dfs(x+d[i],y+d[i+1],k);
}

int main(){
  ll n;
  while(~scanf("%lld",&n)){
    REP(i,12){
      mp[0][i]=-(n&1);
      n/=10;
    }
    REPR(i,12){
      scanf("%lld",&n);
      REP(j,12){
        mp[i][j]=-(n&1);
        n/=10;
      }
    }
    int k = 1;
    int cnt = 0;
    REP(i,12)REP(j,12){
      if(mp[i][j]==-1){
        ++cnt;
        dfs(i,j,k++);
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}