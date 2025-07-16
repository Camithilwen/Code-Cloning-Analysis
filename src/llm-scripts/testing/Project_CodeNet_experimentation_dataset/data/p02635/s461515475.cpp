#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=998244353;
const ll mod=998244353;
signed main(){
    string s;cin>>s;
    reverse(all(s));
    int n=s.size();
    int ma;cin>>ma;
    int cnt=0;
    vector<int>b(0);
    int la=0;
    rep(i,n){
        if(s[i]=='1')cnt++;
        else{
            b.pb(cnt-la);
            la=cnt;
        }
    }
    if(cnt==n){
        cout<<1<<endl;
        return 0;
    }
    ma=min(cnt,ma);
    int m=b.size();
    b.pb(cnt-la);
    vector<vector<vector<int> > > dp(m+1,vector<vector<int> >(ma+2,vector<int>(cnt+2)));
    dp[0][0][0]=1;
    rep(i,m){
        rep(j,ma+1){
            vector<ll>c(cnt+1);
            rep(k,cnt+1){
                c[k]+=dp[i][j][k];
                REP(l,1,b[i]+1){
                    if(j+l>ma)continue;
                    dp[i+1][j+l][k+l]+=dp[i][j][k];
                    dp[i+1][j+l][k+l]%=mod;
                }
                //cout<<dp[i][j][k]<<' ';
            }
            for(int k=cnt-1;k>=0;k--){
                c[k]+=c[k+1];
                c[k]%=mod;
            }
            rep(k,cnt+1){
                dp[i+1][j][k]+=c[k];
                dp[i+1][j][k]%=mod;
            }
            //cout<<endl;
        }
        //cout<<endl;
    }
    ll ans=0;
    rep(j,ma+1){
        rep(k,cnt+1){
            ans+=dp[m][j][k];
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}