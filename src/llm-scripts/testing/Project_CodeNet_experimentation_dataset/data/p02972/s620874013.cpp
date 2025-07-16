#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int a[200010];
int b[200010];

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> a[i+1];

    for(int i = (n+1)/2; i <= n; i++){
        b[i] = a[i];
    }

    for(int k = n; k >= 1; k--){
        int tmp = 0;
        for(int i = 2 * k; i <= n; i += k){
            tmp += b[i];
        }
        tmp += a[k];
        if (tmp%2 == 0) b[k] = 0;
        else b[k] = 1;
    }

    int cnt = 0;
    rep(i, n) cnt += b[i+1];
    cout << cnt << endl;
    if (cnt == 0) return 0;
    rep(i, n) if (b[i+1] > 0) cout << i+1 << " ";
    cout << endl;

    return 0;
}
