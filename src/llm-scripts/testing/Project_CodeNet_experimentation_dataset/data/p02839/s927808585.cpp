//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(int i=0;i<(ll)(n);i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define REP2(i,a,b) for(int i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(int i=a;i>(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入

const int H_MAX=80;
const int W_MAX=80;
const int A_MAX=80;
const int B_MAX=80;

vector<vector<vector<bool>>> dp(H_MAX+1,vector<vector<bool>>(W_MAX+1,vector<bool>(1+A_MAX*(H_MAX+W_MAX),false)));

int main(){
    int H,W;
    cin>>H>>W;
    vector<vector<int>> A(H,vector<int>(W)),B(H,vector<int>(W));
    REP(i,H){
        REP(j,W){
            cin>>A[i][j];
        }
    }

    REP(i,H){
        REP(j,W){
            cin>>B[i][j];
        }
    }
    dp[0][0][0]=true;
    dp[1][0][0]=true;
    dp[0][1][0]=true;
    
    REP(i,H){
        REP(j,W){
            REP(v,1+A_MAX*(H_MAX+W_MAX)){
                if(abs(v-abs(A[i][j]-B[i][j]))<=A_MAX*(H_MAX+W_MAX)){
                    dp[i+1][j+1][v]=dp[i+1][j+1][v]||dp[i][j+1][abs(v-abs(A[i][j]-B[i][j]))];
                    dp[i+1][j+1][v]=dp[i+1][j+1][v]||dp[i+1][j][abs(v-abs(A[i][j]-B[i][j]))];
                }
                if(v+abs(A[i][j]-B[i][j])<=A_MAX*(H_MAX+W_MAX)){
                    dp[i+1][j+1][v]=dp[i+1][j+1][v]||dp[i][j+1][v+abs(A[i][j]-B[i][j])];
                    dp[i+1][j+1][v]=dp[i+1][j+1][v]||dp[i+1][j][v+abs(A[i][j]-B[i][j])];
                }
            }
        }
    }
    REP(v,1+A_MAX*(H_MAX+W_MAX)){
        if(!dp[H][W][v]) continue;
        cout << v <<endl;
        return 0;
    }
}