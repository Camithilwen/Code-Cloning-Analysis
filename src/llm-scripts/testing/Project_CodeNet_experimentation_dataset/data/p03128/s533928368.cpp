#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int need[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int compare(string s, string t) {
    if (s.length() > t.length()) {
        return -1;
    } else if (s.length() < t.length()) {
        return 1;
    } else {
        if (s < t) {
            return 1;
        } else if (s == t) {
            return 0;
        } else {
            return -1;
        }
    }
}

string add(string s, char a) {
    if (s.length() == 0) {
        return string(1, a);
    }
    if (s[0] <= a) {
        return a + s;
    } else if (s.back() >= a) {
        return s + a;
    }
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] < a) {
            return s.substr(0, i) + a + s.substr(i + 1);
        }
    }
    return "";
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    vector<string> dp(N + 1, "");
    for (int a : A) {
        if (need[a] > N)
            continue;
        if (dp[need[a]] == "") {
            dp[need[a]] = to_string(a);
        } else if (compare(dp[need[a]], to_string(a)) == 1) {
            dp[need[a]] = to_string(a);
        }
    }
    for (int i = 0; i <= N; i++) {
        if (dp[i] == "")
            continue;

        for (int a : A) {
            int nxt = i + need[a];
            if (nxt > N)
                continue;

            string added = add(dp[i], ('0' + a));
            if (dp[nxt] == "") {
                dp[nxt] = added;
            } else if (compare(dp[nxt], added) == 1) {
                dp[nxt] = added;
            }
        }
    }
    cout << dp[N] << endl;
}
