#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> Zalgorithm(vector<int> S) {
    vector<int> A(S.size());
    A[0] = S.size();
    int i = 1, j = 0;
    while (i < S.size()) {
        while (i+j < S.size() && S[j] == S[i+j]) ++j;
        A[i] = j;
        if (j == 0) { ++i; continue;}
        int k = 1;
        while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
        i += k; j -= k;
    }
    return A;
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N), S(3 * N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];
    rep(i, N) {
        S[i] = b[i] ^ b[(i + 1) % N];
        S[N + i] = a[i] ^ a[(i + 1) % N];
        S[N + N + i] = a[i] ^ a[(i + 1) % N];
    }
    auto A = Zalgorithm(S);
    rep(i, N) {
        if (A[N + i] >= N) {
            cout << i << " " << (a[i] ^ b[0]) << "\n";
        }
    }
}