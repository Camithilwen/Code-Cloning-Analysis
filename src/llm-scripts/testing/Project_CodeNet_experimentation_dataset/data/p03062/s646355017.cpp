#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=998244353;
const ll INF=2e15;
const double PI=acos(-1);

vector<P> vectorCnt(vector<int> a) {
    sort(a.begin(),a.end());
    int n=a.size();
    vector<pair<int,int>> b;
    int cnt=1;
    rep(i,n-1) {
        if (a[i+1]!=a[i]) {
            b.push_back({cnt,a[i]});
            cnt=1;
        } else {
            ++cnt;
        }
    }
    b.push_back({cnt,a[n-1]});
    return b;
}

int main() {
    ios_base::sync_with_stdio(false); 

    int n;
    cin >> n;
    vector<ll> a(n);
    int cnt=0;
    rep(i,n) {
        cin >> a[i];
        if (a[i]<0) {
            ++cnt;
            a[i]=-a[i];
        }
    }
    sort(a.begin(),a.end());
    ll ans=0;
    rep(i,n) ans+=a[i];
    if (cnt%2==1) ans-=2*a[0];
    cout << ans << endl;
    


    return 0;
}
