#include <bits/stdc++.h>
using namespace std;

bool intCheck(int i, int N, int M, vector<int> S, vector<int> C) {
    string sx = to_string(i);
    if (sx.size() != N) return false;
    for (int j = 0; j < M; j++) {
        if (sx.at(S.at(j)) != (char)C.at(j) + '0') return false;
    }
    return true;
}

int main() {
    int N, M; cin >> N >> M;
    vector<int> s(M), c(M);
    for (int i = 0; i < M; i++) {
        cin >> s.at(i) >> c.at(i);
        s.at(i)--;
    }

    bool ans = true;
    int minv = 1e5, nf = -1;
    for (int i = 0; i < 1000; i++) {
        if (intCheck(i, N, M, s, c)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << nf << endl;
}