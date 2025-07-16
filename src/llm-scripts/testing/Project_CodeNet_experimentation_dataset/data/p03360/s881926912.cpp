#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,ll>
const ll MOD=998244353;
const int INF=1e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    vector<int> a(3);
    int k;
    rep(i,3) cin >> a[i];
    cin >> k;
    sort(a.begin(),a.end(),greater<>());
    rep(i,k) a[0]*=2;
    cout << a[0]+a[1]+a[2] << endl;

    return 0;

}
