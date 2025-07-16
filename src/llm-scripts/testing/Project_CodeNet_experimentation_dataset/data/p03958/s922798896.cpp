#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int K, T; cin >> K >> T;
    vi A(T); rep(i, T) cin >> A[i];

    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    int x = A[0];
    for (int i = 1; i < T; i++) {
        x -= A[i];
    }

    if (x > 0) {
        cout << (x - 1) << endl;
    } else {
        cout << 0 << endl;
    }
}
