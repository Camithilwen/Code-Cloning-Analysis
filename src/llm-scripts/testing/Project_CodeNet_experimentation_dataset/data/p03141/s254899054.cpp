//FIRST THINK THEN CODE.

#include <bits/stdc++.h>
 
 
using namespace std;
 
typedef long long ll;
 
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define rrep(i,a,b) for(ll i=a;i>b;--i)
#define FOR(i,n)  for(ll i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()
#define rev(p) reverse(p.begin(),p.end());
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define popcount(x) __builtin_popcountll(x)
#define sz(x) ((ll)x.size())
const ll M=1000000007;
const ll MM=998244353;
ll begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";

 
ll newmod(ll a,ll b)
 {
  return ((a%b)+b)%b;
}
 
 
ll powM(ll a,ll b,ll m )
{ 
  if(a<=0)return 0;
  a%=m;
  if(!b)return 1;
  ll ans=1LL;
  while(b)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }
 
return ans;
}


 
ll poww(ll a,ll b)
{ 
  
  ll ans=1;
  while(b)
  {
    if(b&1)ans=ans*a;
    a=a*a;
    b>>=1;
  }
 
return ans;

}

template<typename T,typename F>
void chmax( T &a,F b){
  if(b>a)a=b;
}

template<typename T,typename F>
void chmin( T &a,F b){
  if(b<a)a=b;
}



const ll N=1e5+5;

ll vis[600][600];

ll n,m,s,cnt,k;

//cnt goes from 1 to s-k.

char ch[600][600];

bool valid(ll x,ll y){
  if(vis[x][y])return false;
  if(ch[x][y]=='#')return false;
  if(x<1||x>n||y<1||y>m)return false;
  return true;
}

ll dx[]={1,-1,0,0};
ll dy[]={0,0,-1,1};

void dfs(ll x,ll y){
  cnt++;
  if(cnt>s-k)return;
  //cnt++;
  vis[x][y]=1;

  FOR(i,4){
    ll nx=x+dx[i],ny=y+dy[i];
    if(valid(nx,ny))dfs(nx,ny);
  }

}


int main()
{ 

IOS;

ll n;cin>>n;
//ll ans=0;


vl a(n),b(n);

ll ans=0;

vl score(n);

FOR(i,n)cin>>a[i]>>b[i],score[i]=a[i]+b[i],ans-=b[i];

sort(all(score),greater<>());

FOR(i,n){
  //if(i&1)ans-=2*b[i];
  if(i%2==0)ans+=score[i];
}

d1(ans);

//end_routine();

return 0;
 
 }
