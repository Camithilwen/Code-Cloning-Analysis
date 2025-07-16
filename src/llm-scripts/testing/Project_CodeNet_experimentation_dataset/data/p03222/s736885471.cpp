#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 105
#define INF 1000000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 100005;
const int MOD = 1000000007;
int dpo[10];
int dpx[10];
ll dp[105][10];
int w;
int d(int x){
    if(x<=0||x>w)return 1;
    else return (dpo[x]+dpx[x]);
}
int main(){
    int h,k;
    cin>>h>>w>>k;
    dpo[1]=1;dpx[1]=0;
    for(int i=1;i<w;i++){
        dpo[i+1]=dpo[i]+dpx[i];
        dpx[i+1]=dpo[i];
    }
    dp[0][1]=1;
    REP(i,h){
        for(int j=1;j<=w;j++){
            dp[i+1][j]+=(ll)dp[i][j]*d(j-1)*d(w-j);
            //cout<<dp[i][j]<<" "<<d(j-1)<<" "<<d(w-j);
            dp[i+1][j]%=MOD;
            dp[i+1][j]+=dp[i][j+1]*d(w-j-1)*d(j-1);
            dp[i+1][j]+=dp[i][j-1]*d(w-j)*d(j-2);
            dp[i+1][j]%=MOD;
            //OUT(dp[i+1][j]);
        }
    }
    OUT(dp[h][k]);
    return 0;
}