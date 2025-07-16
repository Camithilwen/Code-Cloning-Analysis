#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
    int N, ans = 0;
    cin >> N;
    vector<int> A(N);
    map<int, int> mp;
    rep(i, N) {
        cin >> A[i];
        mp[A[i]]++;
    }
    sort(A.begin(), A.end());
    for (int i = N - 1; i >= 0; i--) {
        if (mp[A[i]] == 0) continue;
        mp[A[i]]--;
        int b = 1;
        while (b <= A[i]) b += b;
        int j = lower_bound(A.begin(), A.end(), b - A[i]) - A.begin();
        if (A[j] != b - A[i]) continue;
        if (mp[A[j]] == 0) continue;
        mp[A[j]]--;
        ans++;
    }
    cout << ans << "\n";
}