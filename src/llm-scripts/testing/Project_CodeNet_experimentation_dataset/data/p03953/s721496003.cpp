#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define REP(i,n) for (int i = 0; i < n; ++i)

const int MAX = 1e5+10;

int N, M;
ll K;
ll X[MAX];

vi mult(vi a, vi b) {
    int n = a.size();
    vi res(n);
    REP (i, n) res[i] = b[a[i]];
    return res;
}

vi swap(vi ord, ll k) {
    int n = ord.size();
    vi res(n);
    REP (i, n) res[i] = i;

    while (k) {
        if (k&1) res = mult(res, ord);
        ord = mult(ord, ord);
        k >>= 1;
    }
    return res;
}

int main() {
    cin >> N;
    REP (i, N) cin >> X[i];

    cin >> M >> K;
    vi ord(N-1);
    REP (i, N-1) ord[i] = i;
    REP (_, M) {
        int a;
        cin >> a;
        int k = ord[a-2];
        ord[a-2] = ord[a-1];
        ord[a-1] = k;
    }

    ord = swap(ord, K);
    ll x = X[0];
    REP (i, N-1) {
        cout << x << "\n";
        x += X[ord[i]+1] - X[ord[i]];
    }
    cout << x << endl;
}
