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
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(ans.rbegin(), ans.rend(), A[i]);
        if (it == ans.rbegin()) ans.push_back(A[i]);
        else *(it-1) = A[i];
    }
    cout << sz(ans) << '\n';
    return 0;
}