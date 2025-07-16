#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    ll N;
    cin >> N;

    ll c[3] = {};
    ll ans = 1;

    rep(i,N) {
        ll a;
        cin >> a;
        bool t = false;
        ll cnt = 0;
        rep(j,3) {
            if (c[j]==a && !t) {
                c[j]++;
                cnt++;
                t = true;
            }
            else if (c[j]==a) {
                cnt++;
            }
        }
        ans*=cnt;
        ans%=MOD;
    }
    cout << ans << endl;
}
