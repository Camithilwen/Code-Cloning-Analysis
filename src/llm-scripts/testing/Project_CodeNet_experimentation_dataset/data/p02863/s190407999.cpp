#include "bits/stdc++.h"

using namespace std;

int dp(int curr, int T, const vector<int>& A, const vector<int>& B, vector<vector<int>>& memo) {
    int N = A.size();
    if (curr == N) {
        return 0;
    }
    if (T <= 0) {
        return 0;
    }
    if (memo[curr][T] >= 0) {
        return memo[curr][T];
    }

    int skip = dp(curr + 1, T, A, B, memo);
    int take = dp(curr + 1, T - A[curr], A, B, memo) + B[curr];
    int ret = max(skip, take);
    memo[curr][T] = ret;
    return ret;
}

void Main() {
    int N, T;
    cin >> N >> T;
    set<pair<int, pair<int, int>>> prep;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        prep.insert(make_pair(a, make_pair(i, b)));
    }
    vector<int> A(N, 0), B(N, 0);
    int cnt = 0;
    for (auto e : prep) {
        A[cnt] = e.first;
        B[cnt] = e.second.second;
        ++cnt;
    }

    vector<vector<int>> memo(N + 10, vector<int>(T + 10, -1));
    int ans = dp(0, T, A, B, memo);
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
