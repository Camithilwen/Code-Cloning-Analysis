//FIRST THINK THEN CODE.

#include <bits/stdc++.h>
 
 
using namespace std;
 
typedef long long ll;
 
//#define MOD 998244353
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
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define popcount(x) __builtin_popcountll(x)

const int M=1000000007;
const int MM=998244353;


 
ll newmod(ll a,ll b)
 {
  return ((a%b)+b)%b;
}
 
 
ll powM(ll a,ll b,ll m )
{ 
  if(m<=1)return 0;
  a%=m;
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

const ll N=1e6+5;

ll sp[N];

void fill(){
  for(int i=1;i<N;i++)sp[i]=i;

    for(int i=2;i<N;i++){
      for(int j=i;j<N;j+=i){
        if(sp[j]==j)sp[j]=i;
      }
    }
}

//vl f(N);

bool prime(ll x){
  if(x<=3)return true;

  for(ll i=2;i*i<=x;i++)if(x%i==0)return false;

    return 1;
}


int main()
{ 

IOS;

fill();

ll a,b;cin>>a>>b;

ll mn=min(a,b);

ll c=0;

set<ll>s;

for(ll i=1;i*i<=a;i++){
  if(a%i==0){
    if(prime(i))s.insert(i);
    if(prime(a/i))s.insert(a/i);
  }
}

for(ll i=1;i*i<=b;i++){
if(b%i==0){
 if( prime(i)&&s.count(i))++c;
 if(i*i!=b&&prime(b/i)&&s.count(b/i))++c;

}

}

//for(auto d:s)cout<<d<<" ";

cout<<c;

return 0;
 
}
