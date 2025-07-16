#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

// a^n mod を計算する
// O(logn)
ll modpow(ll a, ll n, ll mod=998244353) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll cnt[100010];

int main(){
    int n;
    cin>>n;

    vector<ll> d(n);
    rep(i,n){
        cin>>d[i];
        cnt[d[i]]++;
    }

    if(d[0]!=0 || cnt[0]!=1){
        cout<<0<<endl;
        return 0;
    }

    ll ans=1;

    for(int i=1;i<100010;i++){
        ll tmp=modpow(cnt[i],cnt[i+1]);
        ans=(ans*tmp)%998244353;
    }

    cout<<ans<<endl;
}
