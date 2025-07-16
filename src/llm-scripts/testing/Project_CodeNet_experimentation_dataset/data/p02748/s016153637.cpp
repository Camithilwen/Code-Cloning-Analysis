#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 100000100LL

int main(){
    int A, B, M;
    cin >> A >> B >> M;
    ll ans = INF, MINa = INF, MINb = INF;
    vector<ll> a(A), b(B);
    rep(i, A){
        cin >> a[i];
        MINa = min(MINa, a[i]);
    }
    rep(i, B){
        cin >> b[i];
        MINb = min(MINb, b[i]);
    }
    ans = min(ans, MINa + MINb);
    rep(i, M){
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        ll tmp = a[x] + b[y] - c;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
