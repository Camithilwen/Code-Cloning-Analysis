#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const ll mod=1000000007;

ll powmod(ll x,ll y){
    ll res=1;
    for(ll i=0;i<y;i++){
        res=res*x%mod;
    }
    return res;
}



int main(){
    int n;cin >> n;
    ll a[n];
    rep(i,n)cin >> a[i];
    sort(a,a+n);

    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}

