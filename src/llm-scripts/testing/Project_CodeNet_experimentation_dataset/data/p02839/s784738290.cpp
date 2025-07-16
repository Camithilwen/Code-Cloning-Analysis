#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll,ll>
#define PP pair<P,P>
using namespace std;

int dp[80][80][16000];

int main(){
    int h,w; cin >> h >> w;
    int a[h][w];
    int b[h][w];
    rep(i,h)rep(j,w) cin >> a[i][j];
    rep(i,h)rep(j,w) cin >> b[i][j];
    rep(i,h)rep(j,w) a[i][j]=abs(a[i][j]-b[i][j]);
    rep(i,h)rep(j,w)rep(k,16000) dp[i][j][k]=0;
    dp[0][0][a[0][0]]=1;
    rep(i,h)rep(j,w)rep(k,16000){
        if(i>0){
            if(dp[i-1][j][k]){
                dp[i][j][k+a[i][j]]=1;
                dp[i][j][abs(k-a[i][j])]=1;
            }
        }
        if(j>0){
            if(dp[i][j-1][k]){
                dp[i][j][k+a[i][j]]=1;
                dp[i][j][abs(k-a[i][j])]=1;
            }
        }
    }
    int now=0;
    for(;;){
        if(dp[h-1][w-1][now]){
            cout << now << endl;
            return 0;
        }
        now++;
    }
return 0;
}
