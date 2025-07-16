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
    string input; cin >> input;
    vector<int> a(4);
    rep(i,4) a[i] = input[i]-'0';
    rep(i,8) {
        int sum = a[0];
        string s;
        s += (char)('0'+a[0]);
        rep(j,3) {
            if (i & (1<<j)) {
                sum += a[j+1];
                s += '+';
                s += (char)('0'+a[j+1]);
            }
            else {
                sum -= a[j+1];
                s += '-';
                s += (char)('0'+a[j+1]);
            }
        }
        if (sum == 7) {
            cout << s << "=7" << endl;
            return 0;
        }
    }
} 