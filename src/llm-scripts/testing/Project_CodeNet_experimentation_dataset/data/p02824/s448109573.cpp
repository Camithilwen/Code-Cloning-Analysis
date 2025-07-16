#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int64_t N, M, V, P;
    cin >> N >> M >> V >> P;
    vector<int64_t> A(N);
    for(auto &e : A) cin >> e;
    sort(A.begin(), A.end());
    rep(i, N) A[i] += M;
    vector<int64_t> cum(N + 1);
    rep(i, N) cum[i + 1] = cum[i] + A[i];
    int y = N - P;
    auto OK = [&](int x) -> bool {
        if(A[x] + M < A[y]) return false;
        int64_t S = cum[y + 1] - cum[x + 1];
        int64_t D = A[x] * (y - x);
        return S - D <= M * (N - V);
    };
    int l = -1, r = y;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        OK(mid) ? r = mid : l = mid;
    }
    cout << N - r << '\n';
    return 0;
}
