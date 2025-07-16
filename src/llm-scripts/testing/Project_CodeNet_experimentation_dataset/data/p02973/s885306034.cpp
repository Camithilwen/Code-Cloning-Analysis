#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

long long INF = 1e18;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    deque<long long> dp(N, INF);
    for(int i = 0; i < N; i++) {
        long long p = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        if(p == 0) {
            dp.push_front(A[i]);
        } else {
            dp[p - 1] = A[i];
        }
    }
    cout << lower_bound(dp.begin(), dp.end(), INF) - dp.begin() << endl;
}