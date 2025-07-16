#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#ifdef ENABLE_DEBUG
#define dump(a) cerr<<#a<<"="<<a<<endl
#define dumparr(a,n) cerr<<#a<<"["<<n<<"]="<<a[n]<<endl
#else
#define dump(a) 
#define dumparr(a,n) 
#endif
#define FOR(i, a, b) for(ll i = (ll)a;i < (ll)b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(ll i = (ll)b-1LL;i >= (ll)a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)
#define SIGN(a) (a==0?0:(a>0?1:-1))

typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<ll,pll> ppll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ld,ld> pdd;

const ll INF=(1LL<<50);
#if __cplusplus<201700L
ll gcd(ll a, ll b) {
  if(a < b) return gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}
#endif
template<class T>
bool chmax(T& a,const T& b){
  if(a<b){
    a=b;
    return true;
  }
  return false;
}
template<class T>
bool chmin(T& a,const T& b){
  if(a>b){
    a=b;
    return true;
  }
  return false;
}
template<class S,class T>
std::ostream& operator<<(std::ostream& os,pair<S,T> a){
  os << "(" << a.first << "," << a.second << ")";
  return os;
}
template<class T>
std::ostream& operator<<(std::ostream& os,vector<T> a){
  os << "[ ";
  REP(a.size()){
    os<< a[i] << " ";
  }
  os<< " ]";
  return os;
}

const long long MOD = 1000000007;

const long long max_cache=1000000;
long long cache_fact[max_cache],cache_inv_fact[max_cache];
long long combination_cached(long long n,long long r){
  ll m=MOD;
  if(r<0||r>n)return 0;
  if(r==0||r==n)return 1;
  if(n>m){
    std::cerr<<"Combination Error: n is greater than m"<<std::endl;
    exit(1);
  }
  static bool cached=false;
  if(cached==false){
    cached=true;
    cache_inv_fact[1]=1;
    for (long long i = 2; i < max_cache; i++) {
      cache_inv_fact[i]=(m-m/i)*cache_inv_fact[m%i]%m;
    }
    for (long long i = 2; i < max_cache; i++){
      cache_inv_fact[i]=cache_inv_fact[i]*cache_inv_fact[i-1]%m;
    }
    cache_fact[0]=1;
    for (long long i = 1; i < max_cache; i++) {
      cache_fact[i]=cache_fact[i-1]*i%m;
    }
  }
  r=min(r,n-r);
  return cache_fact[n]*cache_inv_fact[r]%m*cache_inv_fact[n-r]%m;
}
void solve(long long N, long long M, long long K){
  ll ans=0;
  For(i,N){
    For(j,M){
      ans=(ans+(i+j)*combination_cached(N*M-2,K-2)%MOD*(N-i)%MOD*(M-j)%MOD)%MOD;
      if(i>0&&j>0){
        ans=(ans+(i+j)*combination_cached(N*M-2,K-2)%MOD*(N-i)%MOD*(M-j)%MOD)%MOD;
      }
    }
  }
  cout<<ans<<endl;
}

int main(){
  cout<<setprecision(1000);
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    long long K;
    scanf("%lld",&K);
    solve(N, M, K);
    return 0;
}
