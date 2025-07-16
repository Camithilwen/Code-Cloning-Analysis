#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    int N, T;
    cin >> N >> T;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
    }
    vector<vector<int>> DP1(N, vector<int>(T, 0)), DP2(N, vector<int>(T, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 1; j < T; j++) {
            if(i == 0) {
                if(0 <= j - A.at(i))
                    DP1.at(i).at(j) = B.at(i);
            } else {
                DP1.at(i).at(j) = max(DP1.at(i - 1).at(j), DP1.at(i).at(j - 1));
                if(0 <= j - A.at(i)) {
                    DP1.at(i).at(j) =
                        max(DP1.at(i).at(j),
                            DP1.at(i - 1).at(j - A.at(i)) + B.at(i));
                }
            }
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        for(int j = 1; j < T; j++) {
            if(i == N - 1) {
                if(0 <= j - A.at(i))
                    DP2.at(i).at(j) = B.at(i);
            } else {
                DP2.at(i).at(j) = max(DP2.at(i + 1).at(j), DP2.at(i).at(j - 1));
                if(0 <= j - A.at(i)) {
                    DP2.at(i).at(j) =
                        max(DP2.at(i).at(j),
                            DP2.at(i + 1).at(j - A.at(i)) + B.at(i));
                }
            }
        }
    }

    ans = max(B.at(0) + DP2.at(1).at(T - 1),
              B.at(N - 1) + DP1.at(N - 2).at(T - 1));
    for(int i = 1; i < N - 1; i++) {
        for(int j = 0; j < T; j++) {
            ans = max(ans, B.at(i) + DP1.at(i - 1).at(j) +
                               DP2.at(i + 1).at(T - j - 1));
        }
    }

    cout << ans << endl;
}