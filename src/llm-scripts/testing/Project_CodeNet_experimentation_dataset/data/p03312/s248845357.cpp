#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 2100100100;
const int MOD = 1e9 + 7;

int N;

int main() {
    cin >> N;
    vector<ll> A(N);
    vector<ll> sum(N + 1, 0);  // sum[i+1] := A[i] までの和
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        sum[i + 1] = sum[i] + A[i];
    }

    ll P, Q, R, S;
    ll ans = 1e18;
    for (int i = 2; i <= N - 2; i++) {  // [0,i) と[i,N) に分ける
        // [0,id) と [id, i)
        int id = lower_bound(ALL(sum), sum[i] / 2) - sum.begin();
        if (i - id < 1) {
            id--;
        } else {
            if (abs(sum[i] - sum[id - 1] * 2) < abs(sum[i] - sum[id] * 2)) id--;
        }
        P = sum[id];
        Q = sum[i] - sum[id];

        // [i, id2) と[id2, N)
        int id2 = lower_bound(ALL(sum), (sum[N] - sum[i]) / 2 + sum[i]) - sum.begin();
        if (N - id2 < 1) {
            id2--;
        } else {
            if (abs((sum[N] - sum[id2 - 1]) - (sum[id2 - 1] - sum[i])) < abs((sum[N] - sum[id2]) - (sum[id2] - sum[i]))) id2--;
        }
        R = sum[N] - sum[id2];
        S = sum[id2] - sum[i];
        //cout << 0 << " " << id << " " << i << " " << id2 << " " << N << " " << P << " " << Q << " " << R << " " << S << " " << ans << endl;
        chmin(ans, max(P, max(Q, max(R, S))) - min(P, min(Q, min(R, S))));
    }
    cout << ans << endl;

    return 0;
}
