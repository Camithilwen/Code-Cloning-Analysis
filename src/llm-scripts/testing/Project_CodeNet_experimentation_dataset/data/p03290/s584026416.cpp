#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 2e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;


int main() {
    int d,g; cin >> d >> g;
    vector<int> p(d), c(d);
    rep(i,d) cin >> p[i] >> c[i];
    int ans = 1001;
    int cnt = 0;
    int score = 0;
    rep(x,1<<d) { //全解きなら1，無解きなら0
        score = 0;
        cnt = 0;
        rep(i,d) {
            if (x & 1<<i) {
                score += 100*(i+1)*p[i]+c[i];
                cnt += p[i];
            }
        }
        //if (score > g) continue;
        int mx;
        rep(i,d) {
            if (!(x & 1<<(d-1-i))) {
                mx = d-1-i;
                break;
            }
        }
        int num = 0;
        while (score < g && num < p[mx]) {
            score += 100*(mx+1);
            num++;
            cnt++;
        }
        if (score >= g) {
            chmin(ans,cnt);
        }
    }
    cout << ans << endl;
}