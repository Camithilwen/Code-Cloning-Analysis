#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
template <typename T> bool chmin(T &x, const T &y) {if (x < y) {x = y; return true;} return false;}
template <typename T> bool chmax(T &x, const T &y) {if (x > y) {x = y; return true;} return false;}

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    
    vector<ll> B(N, 0), C(N, 0);
    B[0] = abs(A[0]);
    for (int i = 1; i < N; ++i) B[i] = B[i - 1] + abs(A[i] - A[i - 1]);
    reverse(ALL(A));
    C[0] = abs(A[0]);
    for (int i = 1; i < N; ++i) C[i] = C[i - 1] + abs(A[i] - A[i - 1]);
    reverse(ALL(A));
    reverse(ALL(C));
    rep(i, N) {
        if (i == 0) cout << C[i + 1] + abs(A[i + 1]) << "\n";
        else if (i == N - 1) cout << B[i - 1] + abs(A[i - 1]) << "\n";
        else cout << B[i - 1] + abs(A[i + 1] - A[i - 1]) + C[i + 1] << "\n";
    }
    return 0;
}
