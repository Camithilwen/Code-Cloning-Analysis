// c
#include <bits/stdc++.h>
#include <string>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second　//pairの二つ目の要素


int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n),b(n);
    bool ac[n]={};
    rep(i,n) cin>>a[i].first>>a[i].second;
    rep(i,n) cin>>b[i].first>>b[i].second;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int j=0;
    int ans=0;
    rep(i,n){
        pair<int,int> sel_b=b[i];
        int max_y=-1;
        int sel_a;
        rep(j,n){
            if(ac[j])continue;
            if(a[j].first<sel_b.first && a[j].second<sel_b.second){
                if(a[j].second>max_y){
                    max_y=a[j].second;
                    sel_a=j;
                }
            }
        }
        if(max_y>-1){
            ans++;
            ac[sel_a]=true;
        }
    }
    cout<<ans<<endl;
    return 0;
}