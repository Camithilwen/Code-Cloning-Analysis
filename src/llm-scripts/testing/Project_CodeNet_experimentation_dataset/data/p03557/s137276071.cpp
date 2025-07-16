#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N;
    cin >> N;
    vector<long long> A(N, 0), B(N, 0), C(N, 0);
    for (long long i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (long long i = 0; i < N; ++i) {
        cin >> B[i];
    }
    for (long long i = 0; i < N; ++i) {
        cin >> C[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    vector<long long> fromAtoB(N, -1);
    vector<long long> fromBtoC(N, -1);
    for (long long i = 0; i < N; ++i) {
        fromAtoB[i] = distance(B.begin(), upper_bound(B.begin(), B.end(), A[i]));
    }
    for (long long i = 0; i < N; ++i) {
        fromBtoC[i] = distance(C.begin(), upper_bound(C.begin(), C.end(), B[i]));
    }

    vector<long long> BC(N, -1);
    for (long long i = 0; i < N; ++i) {
        BC[i] = N - fromBtoC[i];
    }
    vector<long long> accumBC(N, -1);
    for (long long i = N - 1; i >= 0; --i) {
        if (i == N - 1) {
            accumBC[i] = BC[i];
        }
        else {
            accumBC[i] = accumBC[i + 1] + BC[i];
        }
    }

    long long ans = 0;
    for (long long i = 0; i < N; ++i) {
        long long k = fromAtoB[i];
        if (k == N) {
            break;
        }
        ans += accumBC[k];
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
