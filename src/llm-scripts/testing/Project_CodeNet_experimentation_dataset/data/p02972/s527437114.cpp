#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N+1);  // 1-indexed
    rep(i, N) cin >> A[i+1];
    vector<int> ans;
    for (int i = N; i >= 1; i--) {
        int temp = 0;
        for (int j = i; j <= N; j += i) {
            temp ^= A[j];
        }
        if (A[i] ^ temp) A[i] ^= 1;
        if (A[i]) ans.push_back(i);
    }
    cout << sz(ans) << '\n';
    rep(i, sz(ans)) printf("%d%c", ans[i], i+1==sz(ans) ? '\n' : ' ');
    return 0;
}