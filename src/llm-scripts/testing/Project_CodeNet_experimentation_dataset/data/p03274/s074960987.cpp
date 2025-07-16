#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i = 0;i < n;++i)
const ll mod = 1000000007;
const int INF = 1001001001;

int main(){

    int n,k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    int ans = INF;
    rep(i,n-k+1) {
        ans = min(ans,abs(x[i])+abs(x[i+k-1]-x[i]));
        ans = min(ans,abs(x[i+k-1])+abs(x[i+k-1]-x[i]));
    }
    cout << ans << endl;

    return 0;
}