//
//  main.cpp
//  DPu
#include <iostream>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using P=pair<int,int>;
using ll = long long;
ll dp[1<<16]={};
ll cost[1<<16]={};
int main(int argc, const char * argv[]) {
    int n;
    cin >>n;
    ll a[n][n];
    rep(i,n) rep(j,n) cin>>a[i][j];
    
    for (int s=1; s<(1<<n); s++) {
        for (int i=0; i<n; i++) {
            if((s>>i)%2==0) continue;
            for (int j=i+1;j<n; j++) {
                if((s>>j)%2==0)continue;
                cost[s]+=a[i][j];
            }
        }
    }
    for (int s=1; s<(1<<n); s++) { // 全集合
       for (int t=(1<<n)-1; t>=0; --t) { // 集合Sの部分集合T
           t&=s;    // 部分集合tの全列挙の方法、処理はこの下に書く
                    // https://primenumber.hatenadiary.jp/entry/2016/12/01/000000
           dp[s]=max(dp[s],dp[s-t]+cost[t]);
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}
