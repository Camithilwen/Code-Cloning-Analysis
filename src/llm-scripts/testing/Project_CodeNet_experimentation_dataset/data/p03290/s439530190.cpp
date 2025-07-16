#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
 
 
using namespace std;
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007
//#define mod 998244353

int D,G;
int p[15],c[15];
int dp[15][1500];
signed main(){
    scanf("%lld %lld",&D,&G);
    int maxp=0;
    rep(i,D){
        scanf("%lld %lld",&p[i],&c[i]);
        maxp=max(maxp,p[i]);
    }
    rep(i,D+1)rep(j,D*maxp+1)dp[i][j]=-INF;
    rep(i,D){
        rep(j,D*maxp+1){
            if(i==0&&j==0)dp[i][j]=0;
            rep(p_num,p[i]+1){
                if(p_num!=p[i])dp[i+1][j+p_num]=max(dp[i+1][j+p_num],dp[i][j]+p_num*(i+1)*100);
                else dp[i+1][j+p_num]=max(dp[i+1][j+p_num],dp[i][j]+p_num*(i+1)*100+c[i]);
            }
        }
    }
    int ans=-1;
    rep(j,D*maxp+1){
        //printf("%lld/",dp[D][j]);
        if(dp[D][j]>=G){ans=j;break;}
    }
    printf("%lld\n",ans);
}