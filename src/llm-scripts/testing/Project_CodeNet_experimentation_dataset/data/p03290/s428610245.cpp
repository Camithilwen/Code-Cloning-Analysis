#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int D, G;
    cin >> D >> G;
    vector<int> P(D), C(D);
    rep(i, D) cin >> P[i] >> C[i];
    int res = INF;
    for(int bit = 0; bit < (1 << D); bit++) {
        int score = 0;
        int num = 0;
        for(int i = 0; i < D; i++) {
            if(bit & (1 << i)) {
                score += C[i];
                score += 100 * (i + 1) * P[i];
                num += P[i];
            }
        }
        vector<int> list;
        for(int i = D - 1; i >= 0; i--) {
            if(!(bit & (1 << i))) {
                for(int j = 0; j < P[i]; j++)
                    list.pb(100 * (i + 1));
            }
        }
        for(auto x : list) {
            if(score >= G)
                break;
            score += x;
            num++;
        }
        if(score >= G) {
            res = min(res, num);
        }
    }
    cout << res << endl;
    return 0;
}