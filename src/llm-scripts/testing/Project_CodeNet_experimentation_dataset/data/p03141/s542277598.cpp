#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    vector<int> C(N);
    ll totalB = 0;
    rep(i, N){
        cin >> A[i] >> B[i];
        C[i] = A[i] + B[i];
        totalB += B[i];
    }

    sort(C.begin(), C.end());
    int n = (N+1) / 2;
    ll totalA = 0;
    rep(i, n){
        totalA += C[N-1-i*2];
    }

    cout << totalA - totalB << endl;

    return 0;
}