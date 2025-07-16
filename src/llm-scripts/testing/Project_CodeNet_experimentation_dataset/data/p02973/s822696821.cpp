#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> memo = {-A[0]};
    rep2(i, 1, N) {
        int tmp = upper_bound(ALL(memo), -A[i]) - memo.begin();
        if (tmp == memo.size()) memo.push_back(-A[i]);
        else memo[tmp] = -A[i];
    }
    cout << memo.size() << endl;
}
