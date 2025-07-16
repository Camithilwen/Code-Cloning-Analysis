#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <numeric>
#define IINF 1000000000
#define INF 3223372036854775807
#define MOD 1000000007
#define mod 998244353
#define INT_MAX_ 2147483647
#define EPS (1e-10)
#define REP(i, a, n) fo-r (ll i = a; i < (ll)(n); i++)
#define REPE(i, a, n) for (ll i = a; i <= (ll)(n); i++)
//#define rep(i,n)for (ll i = 0; i < (ll)(n); i++)
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
#define me memset
#define bit(n,k) ((n>>k)&1)
#define lg length()
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int>Pin;
typedef pair<ll,ll>Pll;
template<class T> using V=vector<T>;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T> >;
long long GCD(long long a, long long b) {return b?GCD(b,a%b):a;}
long long LCM(long long a, long long b) {return a/GCD(a,b)*b;}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define invp(a,p)pom(a,p-2,p)
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
ll cmp1(pair<Pll,ll> a,pair<Pll,ll> b){
        return a.fi.se>b.fi.se;
}
ll cmp2(pair<ll,ll> a,pair<ll,ll> b){
    if(a.se!=b.se)
        return a.se<b.se;
    else
        return a.fi<b.fi;
}
//----------------------------------------------------------------------
bool dp[80][80][2*160*80+1];
//----------------------------------------------------------------------
int main(int argc, char * argv[]){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------  
    //ll begin_t=clock();
    //freopen("big.txt", "r", stdin);
    //freopen("out3.txt", "w", stdout);
    //-----------------------------
    ll h,w;cin>>h>>w;
    ll a[h+1][w+1];
    ll b[h+1][w+1];
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin>>b[i][j];
        }
    }
    dp[0][0][a[0][0]-b[0][0]+160*80]=1;
    dp[0][0][b[0][0]-a[0][0]+160*80]=1;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            if(i>0){
                for(ll k=0;k<=2*160*80;k++){
                    if(dp[i-1][j][k]){
                        dp[i][j][k+a[i][j]-b[i][j]]=1;
                        dp[i][j][k+b[i][j]-a[i][j]]=1;
                    }
                }
            }
            if(j>0){
                for(ll k=0;k<=2*160*80;k++){
                    if(dp[i][j-1][k]){
                        dp[i][j][k+a[i][j]-b[i][j]]=1;
                        dp[i][j][k+b[i][j]-a[i][j]]=1;
                    }
                }
            }
        }
    }
    ll ans=INF;
    for(ll k=0;k<=2*160*80;k++){
        if(dp[h-1][w-1][k]){
            chmin(ans,abs(k-160*80));
        }
    }
    cout<<ans<<endl;
    //------------------------------
    //fclose(stdin);
    //fclose(stdout);
    //ll end_t=clock();cout<<"time="<<end_t-begin_t<<"ms"<<endl;
    //------------------------------- 
    return 0;
}
//----------------------------------------------------------------------




































