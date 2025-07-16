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

map<ll,ll> cnt[2];
ll D;

ll dfs(const vector<ll>& a,ll i,ll sum){
  // if(sum>D*1000||sum<-D*1000)return 0;

  ll n=a.size();
  if(i==n){
    if(sum==D) return 1;
    else return 0;
  }else{
    ll res=0;
    bool done=false;
    repl(c,-9,9+1){
      if(sum+c*a[i]>D){
        res+=dfs(a,i+1,sum+(c-1)*a[i])*cnt[(i!=0?0:1)][c-1];
        res+=dfs(a,i+1,sum+c*a[i])*cnt[(i!=0?0:1)][c];
        done=true;
        break;
      }
    }
    if(!done){
      res+=dfs(a,i+1,sum+9*a[i])*cnt[(i!=0?0:1)][9];
    }
    return res;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  rep(a,10)rep(b,10){
    cnt[0][b-a]++;
    if(a>0)cnt[1][b-a]++;
  }

  cin>>D;
  ll res=0;
  rep(d,18){
    vector<ll> ds;
    rep(i,d/2+1){
      ll p1=pow(10,i);
      ll p2=pow(10,d-i);

      ll dif=p2-p1;
      ds.push_back(dif);
    }
    ll t=1;
    if(ds.back()==0){
      t*=10; ds.pop_back();
    }
    res+=dfs(ds,0,0)*t;
  }
  cout<<res<<endl;

  return 0;
}
