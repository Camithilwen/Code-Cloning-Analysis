#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pi M_PI
#define R cin>>
#define Z class
#define ll long long
#define ln cout<<'\n'
#define in(a) insert(a)
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define iter(c) __typeof((c).begin())
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
template<Z A>void pr(A a){cout<<a;ln;}
template<Z A,Z B>void pr(A a,B b){cout<<a<<' ';pr(b);}
template<Z A,Z B,Z C>void pr(A a,B b,C c){cout<<a<<' ';pr(b,c);}
template<Z A,Z B,Z C,Z D>void pr(A a,B b,C c,D d){cout<<a<<' ';pr(b,c,d);}
template<Z A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
ll check(ll n,ll m,ll x,ll y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<61,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,int> P;

class RUQ{
public:
  int t[555555],v[555555],c;
  void init(){
    c=0;
    memset(t,0,sizeof(t));
    memset(v,0,sizeof(v));
  }
  void update(int a,int b,int x) {
    c++;
    v[c]=x;
    update2(a,b,c);
  }
  void update2(int a,int b,int x,int k=0,int l=0,int r=1<<18){
    if(b<=l||r<=a)return;
    if(a<=l&&r<=b){t[k]=max(t[k],x);return;}
    int m=(l+r)/2;
    update2(a,b,x,k*2+1,l,m);
    update2(a,b,x,k*2+2,m,r);
  }
  int query(int i){
    i+=(1<<18)-1;
    int res=t[i];
    while(i){
      i=(i-1)/2;
      res=max(res,t[i]);
    }
    return v[res];
  }
};

void Main() {
  int n,m;
  cin >> n >> m;
  RUQ r;
  r.init();
  r.v[0]=INT_MAX;
  while(m--) {
    int z,x;
    cin >> z >> x;
    if(!z) {
      int y,w;
      cin >> y >> w;
      r.update(x,y+1,w);
    } else pr(r.query(x));
  }
}

int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}
