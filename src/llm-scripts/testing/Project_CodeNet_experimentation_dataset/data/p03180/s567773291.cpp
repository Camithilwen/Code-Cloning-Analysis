#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=16,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n;
int  g[mxN][mxN];
int dp[(1<<16)],sum[(1<<16)];
void solve(int idx,int mask,int temp,vi& a,int k){
    if(idx==sz(a)){
        dp[mask]=max(dp[mask],k+sum[temp]);
        return;
    }
    solve(idx+1,mask,temp,a,k);
    solve(idx+1,mask^(1<<a[idx]),temp^(1<<a[idx]),a,k);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }
    for(int mask=0;mask<=(1<<n)-1;mask++){
        for(int i=0;i<n;i++){
            if(!(mask & (1<<i)))continue;
            for(int j=i+1;j<n;j++){
                if((mask & (1<<j))){
                    sum[mask]+=g[i][j];
                }
            }
        }
    }
    for(int mask=0;mask<(1<<n);mask++){
        vi aux;
        for(int i=0;i<n;i++){
            if(!(mask & (1<<i)))aux.pb(i);
            solve(0,mask,0,aux,dp[mask]);
        }

    }
    cout<<dp[(1<<n)-1];
    
}