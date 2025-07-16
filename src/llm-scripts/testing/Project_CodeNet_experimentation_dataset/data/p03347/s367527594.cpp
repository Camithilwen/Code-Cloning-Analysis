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
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    ll ans = 0;
    int ct = 0;
    bool flag = false;
    repd(i, 1, N) {
        if (A[i] > ct + 1) {
            ans = -1;
            ct = 0;
            break;
        }
        else if (A[i] == ct + 1) {
            ct = A[i];
        }
        else {
            ans += ct;
            ct = A[i];
        }
    }

    ans += ct;
    if (A[0] >= 1) ans = -1;
    cout << ans << endl;
    return 0;
}