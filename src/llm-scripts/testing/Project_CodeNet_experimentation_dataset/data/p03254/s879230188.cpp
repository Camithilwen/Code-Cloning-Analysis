#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    ll now = 0;
    int ans = n;
    rep(i,n){
        now += a[i];
        if(now > x){
            ans = i;
            break;
        }
    }

    if(ans==n&&now!=x) cout << (n-1) << endl;
    else cout << ans << endl;
    return 0;
}