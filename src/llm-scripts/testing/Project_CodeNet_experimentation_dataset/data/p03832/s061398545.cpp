#include<bits/stdc++.h>
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n,m) for(int i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll beki(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k%2==1){
            ret*=now;
            ret%=mod;
        }
        now*=now;
        now%=mod;
        k/=2;
    }
    return ret;
}
ll gyaku(ll n){
    return beki(n,mod-2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;cin>>n;
    ll a,b,c,d;cin>>a>>b>>c>>d;
    ll dp[n+1][n+1];
    rep(i,0,n+1)rep(j,0,n+1)dp[i][j]=0;
    dp[a-1][0]=1;
    ll nck[1001][1001];
    rep(i,0,1001)nck[i][0]=1;
    rep(i,0,1001)nck[i][i]=1;
  ll gya[1001];
  rep(i,1,1001)gya[i]=gyaku(i);
    rep(i,1,1001){
        rep(j,1,i){
            nck[i][j]=nck[i-1][j-1]+nck[i-1][j];
            nck[i][j]%=mod;
        }
    }
    rep(i,a-1,b){
        int t=0;
        rep(j,0,n+1){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=mod;
            if(t==1)continue;
            ll sum=1;
            ll now=n-j;
            rep(k,0,c){
                if(now<0){
                    sum=-1;
                    break;
                }
                sum*=nck[now][i+1];
                sum%=mod;
                sum*=gya[k+1];
                sum%=mod;
                now-=i+1;
                
            }
            if(sum==-1){
                t=1;
                continue;
            }
            rep(k,c,d+1){
                if(j+(i+1)*k>n)break;
                dp[i+1][j+(i+1)*k]+=dp[i][j]*sum;
                dp[i+1][j+(i+1)*k]%=mod;
                sum*=nck[n-(j+(i+1)*k)][i+1];
                sum%=mod;
                sum*=gya[k+1];
                sum%=mod;
            }
            
        }
    }
    cout<<dp[b][n]<<endl;
    
}

