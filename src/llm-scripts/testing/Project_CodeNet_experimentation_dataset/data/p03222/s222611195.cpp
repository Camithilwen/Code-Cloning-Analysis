#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(ll i=0;i<n;i++)
#define repn(i,n) for(ll i=1;i<=n;i++)
using namespace std;
typedef long long ll;

const ll MOD=1'000'000'007;
const ll c[7]={1,2,3,5,8,13,21};
ll H,W,K;
ll dp[101][8];

int main(){
    rep(i,101) fill(dp[i],dp[i]+8,0);
    dp[0][0]=1;
    cin>>H>>W>>K;

    repn(i,H){
        rep(j,W){
            if(j==0) 
                dp[i][j]=dp[i-1][j]*c[max((ll)0,W-2)]
                        +dp[i-1][j+1]*c[max((ll)0,W-3)];
            else if(j==W-1) 
                dp[i][j]=dp[i-1][j]*c[max((ll)0,W-2)]
                        +dp[i-1][j-1]*c[max((ll)0,W-3)];
            else 
                dp[i][j]=dp[i-1][j-1]*c[max((ll)0,j-2)]*c[max((ll)0,W-j-2)]
                        +dp[i-1][j]*c[max((ll)0,j-1)]*c[max((ll)0,W-j-2)]
                        +dp[i-1][j+1]*c[max((ll)0,j-1)]*c[max((ll)0,W-j-3)];
            dp[i][j]%=MOD;
        }
    }

    ll ans=dp[H][K-1]>=0?dp[H][K-1]:dp[H][K-1]+MOD;
    cout<<ans<<endl;
}