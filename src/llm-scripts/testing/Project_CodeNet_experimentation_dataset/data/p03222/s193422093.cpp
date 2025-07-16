#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
//小数点以下　cout << fixed << setprecision(10) << num << endl;
//桁数はlog10(mid)でやれ　log(mid)/log(10)はWA
//long*long<0で判定するな
//開区間と閉区間
//アルファベットが何番目かは x=s[i]-'a'
//bfsはmain()内で　rep(i,h)rep(j,w)rep(i,4)でバグ
//切り上げ：(a+(b-1))/b
//32bit以上は 1ull<<j
// map 初期値0 for(auto itr=mp.begin();itr!=mp.end();++itr) itr->fi itr->se で全探索
// for(auto u:mp) u.fi u.se も可能
//n個のgcd,lcmは一つずつみて更新していく
//大きな数を扱うときは素因数分解した形で持っておく
// (l/a[i]) = l*powmod(a[i],MOD-2)%MOD;
//auto itr=lower_bound(ALL(a),key) a[itr-a.begin()]
const ll MOD = 1000000007;
signed main(){
    int h,w,k;
    cin >> h >> w >> k;
    k--;
    if(w==1){
        if(k==0) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    ll num[w-1],no[w];
    
    rep(i,w-1) num[i]=0;
    rep(i,w) no[i]=0;
    
    rep(i,(1<<(w-1))){
        bool kuji[w-1];
        rep(j,w-1){
            if(i&(1<<j)){
                kuji[j]=1;
            }else kuji[j]=0;
        }
        bool aa=0;
        rep(j,w-2) if(kuji[j]&&kuji[j+1]) aa=1;
        if(aa) continue;
        rep(j,w-1){
            if(kuji[j]) num[j]++;
            if(0<j&&!kuji[j]&&!kuji[j-1]) no[j]++;
        }
        if(!kuji[0]) no[0]++;
        if(!kuji[w-2]) no[w-1]++;
    }
    ll dp[h+1][w];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    rep(i,h+1){
        if(i==0) continue;
        rep(j,w){
            if(j>0) dp[i][j]+=(dp[i-1][j-1]*num[j-1])%MOD;
            dp[i][j]%=MOD;
            if(j+1<w) dp[i][j]+=(dp[i-1][j+1]*num[j])%MOD;
            dp[i][j]%=MOD;
            dp[i][j]+=(dp[i-1][j]*no[j])%MOD;
            dp[i][j]%=MOD;
        }
    }
    cout << dp[h][k] << endl;
}
