#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int K, T; cin >> K >> T;
    vector<int> A(T);
    rep(i, T) cin >> A.at(i);
    sort(A.begin(), A.end(), greater<int>());
    if (A[0] < K - A[0]) {
        cout << 0 << endl;
    } else {
        cout << A[0] - (K - A[0]) - 1 << endl;
    }
}
