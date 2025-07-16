#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int M;
    cin >> M;
    ll S = 0;
    ll C = 0;
    rep(i, M) {
        ll d, c;
        cin >> d >> c;
        S += d * c;
        C += c;
    }

    ll ans = C - 1;
    ans += (S - 1) / 9;
    cout << ans << endl;
    return 0;
}