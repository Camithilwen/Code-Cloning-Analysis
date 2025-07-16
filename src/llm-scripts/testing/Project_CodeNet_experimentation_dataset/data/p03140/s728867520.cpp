#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N, ans = 0;
    string A, B, C;
    cin >> N >> A >> B >> C;
    rep(i, N) {
        if (A[i] == B[i]) {
            if (A[i] != C[i]) ans++;
        } else if (A[i] == C[i]) {
            ans++;
        } else if (B[i] == C[i]) {
            ans++;
        } else {
            ans += 2;
        }
    }
    cout << ans << "\n";
}