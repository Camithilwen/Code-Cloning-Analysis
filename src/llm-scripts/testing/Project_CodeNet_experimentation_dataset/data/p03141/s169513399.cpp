#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


int main(){
    int n;
    cin >> n;

    vector<ll> ab;
    ll cnt = 0;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        ab.push_back(a+b);
        cnt += b;
    }
    sort(ab.begin(), ab.end(), greater<ll>());
    ll ans = 0;
    rep(i, (n+1)/2){
        ans += ab[2 * i];
    }
    ans -= cnt;

    cout << ans << endl;

    return 0;
}