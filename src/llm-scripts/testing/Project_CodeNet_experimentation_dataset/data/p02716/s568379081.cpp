//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const ll INF=1e+17;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入


int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    vector<vector<ll>> dp(N+1,vector<ll>(2,0));
    dp[0][0]=0;
    dp[0][1]=0;
    dp[1][0]=0;
    dp[1][1]=A[0];
    
    REP2(i,1,N){
        if(i%2==1){
            dp[i+1][0]=max(dp[i][1],dp[i-1][0]+A[i]);
        }else{
            dp[i+1][0]=max(dp[i][0],dp[i-1][0]+A[i]);
            dp[i+1][1]=dp[i-1][1]+A[i];
        }
    }
    cout<<dp[N][0]<<endl;
}