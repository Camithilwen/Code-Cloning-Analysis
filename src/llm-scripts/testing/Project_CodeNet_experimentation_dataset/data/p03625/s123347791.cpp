#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    ll N, a, H = 0, W = 0;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    for(int i=N-1; i>=1; i--) {
        if(A[i] == A[i-1]) {
            if(H == 0) H = A[i];
            else if(W == 0) W = A[i];
            else break;
            i--;
        }
    }
    cout << H * W << endl;
}