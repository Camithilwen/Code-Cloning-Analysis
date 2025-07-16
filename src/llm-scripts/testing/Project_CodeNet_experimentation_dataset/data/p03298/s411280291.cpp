#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    string S;
    cin >> N >> S;

    reverse(S.begin() + N, S.end());

    map<pair<string, string>, int64_t> mp[2];
    for (int64_t i = 0; i < (1LL << N); i++) {
        for (int64_t j = 0; j < 2; j++) {
            string str1, str2;
            for (int64_t k = 0; k < N; k++) {
                if (i & (1LL << k)) {
                    str1 += S[k + N * j];
                } else {
                    str2 += S[k + N * j];
                }
            }

            mp[j][make_pair(str1, str2)]++;
        }
    }

    int64_t ans = 0;
    for (const auto& p : mp[0]) {
        ans += mp[0][p.first] * mp[1][p.first];
    }
    cout << ans << endl;
}