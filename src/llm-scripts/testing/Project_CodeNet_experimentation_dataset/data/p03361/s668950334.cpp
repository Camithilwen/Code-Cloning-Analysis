#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const char nl = '\n';

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int h, w; cin >> h >> w;
    int canvas[h + 2][w + 2];
    FOR(i, 1, h + 1) {
        string s; cin >> s;
        FOR(j, 1, w + 1) canvas[i][j] = s[j];
    }
    bool ok = true;
    F0R(i, h) {
        F0R(j, w) {
            if (canvas[i][j] == '#') {
                if (canvas[i+1][j] == '.' && canvas[i - 1][j] == '.' && canvas[i][j + 1] == '.' && canvas[i][j - 1] == '.') {
                    ok = false;
                    break;
                }
            }
        }
    }
    cout << (ok ? "Yes\n": "No\n");
}