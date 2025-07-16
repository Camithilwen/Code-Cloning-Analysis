#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    vector<string> ans(100);
    rep(i, 100) {
        rep(ii, 100) {
            ans[i] += ((i >= 50) ? "." : "#");
        }
    }
    rep(i, a - 1) {
        ans[i * 2 / 100 * 2][i * 2 % 100] = '.';
    }
    rep(i, b - 1) {
        ans[99 - i * 2 / 100 * 2][i * 2 % 100] = '#';
    }
    printf("100 100\n");
    rep(i, 100) printf("%s\n", ans[i].c_str());
    return 0;
}