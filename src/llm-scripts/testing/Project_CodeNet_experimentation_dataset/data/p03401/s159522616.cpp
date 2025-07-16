#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N+2);
    A[0] = 0;
    for (int i = 1; i <= N; i++) cin >> A[i];
    A[N+1] = 0;

    ll sum = 0;
    for (int i = 0; i <= N; i++){
      sum += abs(A[i] - A[i + 1]);
    }

    for (int i = 0; i < N; i++) {
      cout << sum - abs(A[i + 1] - A[i]) - abs(A[i + 1] - A[i + 2]) +abs(A[i] - A[i + 2])<< endl;
    }
    return 0;
}