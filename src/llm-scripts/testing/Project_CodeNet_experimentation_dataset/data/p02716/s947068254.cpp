#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

ll dp[200005][5];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    V<ll> a(n);
    cinf(n,a);
    ll k=1+n%2;
    rep(i,n+1)rep(j,k+1)dp[i][j]=-INF;
    dp[0][0]=0;
    rep(i,n){
        rep(j,k+1){
            chmax(dp[i+1][j+1],dp[i][j]);
            ll now=dp[i][j];
            if((i+j)%2==0) now+=a[i];
            chmax(dp[i+1][j],now);
        }
    }
    cout<<dp[n][k]<<endl;
}
//ペナルティ出しても焦らない　ACできると信じろ！！！
/*
V,P(大文字)使用不可
乗算などの際にオーバーフローに注意せよ！
(適切にmodをとれ　にぶたんで途中で切り上げろ)
制約をよく読め！
(全探索できるなら全探索しろ)
stringの計算量(扱い)注意
コーナー注意！(特に数値が小さいものについては要検証)
N行出力のときは'\n'
グリッド上では行先が範囲内におさまるかif文で確認(RE注意)
if文ではちゃんと比較演算子==を使え(=でもエラー出ない)
配列(vector)の大きさが0か1以上かで場合分けせよ(RE注意)
(vector<int> a(m)でm==0というものはできない)
modはなるべく最後に取れ！
*/