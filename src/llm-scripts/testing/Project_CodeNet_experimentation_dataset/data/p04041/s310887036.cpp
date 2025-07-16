#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const int INF (1 << 30);
const ll LLINF (1LL << 55LL);
const int MOD = 1000000007;
const int MAX = 510000;
const double pi = acos(-1);
const double eps = 1e-9;

ll C[3000][3000];
void com(){
    C[0][0]=1;
    for(ll i=1;i<2010;i++){
        for(ll j=0;j<i+1;j++){
            if(j==0||j==i) C[i][j]=1;
            else{
                C[i][j]=C[i-1][j-1]+C[i-1][j];
                C[i][j]%=1000000007;
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    com();
    ll n,x,y,z,ans=1;
    ll dp[50][1<<19];
    cin>>n>>x>>y>>z;
    rep(i,n){
        ans*=10;
        ans%=MOD;
    }
    ll ng = 0;
    ng |= 1<<z;
    ng |= 1<<(y+z);
    ng |= 1<<(x+y+z);
    ll mask = 1<<(x+y+z+1); mask--;
    rep(i,42)rep(j,(1<<19)) dp[i][j]=0;
    dp[0][1]=1;
    rep(i,n){
        rep(bit,mask+1){
            rep2(j,1,11){
                ll ns = ((bit<<j)&mask)+1;
                if((ns&ng) == ng) continue;
                dp[i+1][ns] += dp[i][bit];
                dp[i+1][ns] %= MOD;
            }
        }
    }
    rep(i,mask){
        ans-=dp[n][i];
        ans%=MOD;
    }
    cout<<(ans+MOD)%MOD<<endl;
    return 0;
}