#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


ll n;
vector<ll>a;

int main(){
    cin>>n;
    a.resize(n+1);
    rep(i,n)cin>>a[i+1];
    vector<ll>ans(n+1,0);
    ll M = 0;
    for(int i=n;i>=1;i--){
        int j=2;
        int cnt = 0;
        //倍数の和を求める
        while (i*j<=n){
            if(ans[i*j]==1)cnt++;
            j++;
        }
        if((a[i]%2)!=(cnt%2)){
            ans[i]++;
            M++;
        }
    }
    cout << M << endl;
    for(int i=1;i<=n;i++){
        if(ans[i]==1)cout<<i<<endl;
    }
    return 0;
}
