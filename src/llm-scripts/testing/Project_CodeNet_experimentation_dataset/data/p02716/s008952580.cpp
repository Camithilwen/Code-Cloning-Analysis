#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int n;
ll a[200001];
ll dp[2][100011][2];
int main(){
    cin>>n;
    rep(i,n) cin>>a[i];
    int l,r,cur=0;
    rep(i,2)rep(j,100011)rep(k,2) dp[i][j][k]=-1000100010001000100;
    dp[0][0][0]=0,dp[0][0][1]=0;
    rep(i,n){
        cur=i%2;
        r=(i+1)/2,l=max(0,i/2-1);
        FOR(j,l,r+1){
            dp[cur^1][j][0]=max(dp[cur^1][j][0],dp[cur][j][1]);
            dp[cur^1][j][0]=max(dp[cur^1][j][0],dp[cur][j][0]);
            dp[cur^1][j+1][1]=max(dp[cur^1][j+1][1],dp[cur][j][0]+a[i]);
        }
    }
    cout<<max(dp[n%2][n/2][0],dp[n%2][n/2][1])<<endl;
    return 0;
}