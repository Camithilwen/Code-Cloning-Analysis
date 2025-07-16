#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const int needs[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

bool compare(vector<int>& a, vector<int>& b, int size) {
    int cnta = 0, cntb = 0;
    for (int i = 0; i < size; i++) {
        cnta += a[i];
        cntb += b[i];
    }
    if (cnta != cntb) {
        return cnta > cntb;
    } else {
        return a > b;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    vector<vector<int>> dp(N + 1, vector<int>(M, -1));
    for (int i = 0; i < M; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int m = 0; m < M; m++) {
            if (dp[i][0] == -1) {
                continue;
            }
            vector<int> tmp = dp[i];
            tmp[m]++;
            if (i + needs[A[m]] <= N && compare(tmp, dp[i + needs[A[m]]], M)) {
                dp[i + needs[A[m]]] = tmp;
            }
        }
    }
    // for (int n = 0; n <= N; n++) {
    //     cout << "n = " << n << endl;
    //     for (int i = 0; i < M; i++) {
    //         cout << A[i] << " " << dp[n][i] << endl;
    //     }
    // }

    string ans = "";
    for (int i = 0; i < M; i++) {
        ans += string(dp[N][i], A[i] + '0');
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
