#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

const int N=500;
bool isprime[1000010];
vector<ll> ps;
ll res[N][N];
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};

ll lcm(ll a,ll b){
  return (a/__gcd(a,b))*b;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  repl(i,2,1000000)isprime[i]=true;
  repl(i,2,1000000){
    if(isprime[i]){
      ps.push_back(i);
      for(ll j=i*2;j<1000000;j+=i)isprime[j]=false;
    }
  }

  while(ps.size()>1000)ps.pop_back();


    rep(i,N)rep(j,N)res[i][j]=1;
    for(ll s=0;s<2*N-1;s+=2){
      rep(i,N){
        ll j=s-i;
        if(j>=N||j<0)continue;
        res[i][j]*=ps[s/2];
      }
      rep(i,N){
        ll s2=s-N+2;
        ll j=i-s2;
        if(j>=N||j<0)continue;
        res[i][j]*=ps[N+(s/2)];
      }
    }

    rep(i,N)rep(j,N){
      if(res[i][j]==1){
        ll lc=1;
        rep(dir,4){
          int ni=i+di[dir],nj=j+dj[dir];
          if(ni<0||ni>=N||nj<0||nj>=N)continue;
          lc=lcm(lc,res[ni][nj]);
        }
        res[i][j]=lc+1;
      }
    }

  int n;
  cin>>n;
  rep(i,n){
    rep(j,n){
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
