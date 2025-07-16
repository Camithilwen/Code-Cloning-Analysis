#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<map<int, int>> start_length(N, map<int, int>());
    for (int i = 0; i < M; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        if (start_length[l].count(r - l) == 0) {
            start_length[l].insert(make_pair(r - l, 0));
        }
        start_length[l][r - l] += 1;
    }
    vector<vector<int>> start_lengthLess(N, vector<int>());
    for (int i = 0; i < N; ++i) {
        const map<int, int>& length_num = start_length[i];
        vector<int> length(N + 1, 0);
        for (auto e : length_num) {
            length[e.first] = e.second;
        }
        vector<int> accumLength(N + 1, 0);
        accumLength[0] = length[0];
        for (int j = 1; j < accumLength.size(); ++j) {
            accumLength[j] = accumLength[j - 1] + length[j];
        }
        start_lengthLess[i] = accumLength;
    }

    for (int i = 0; i < Q; ++i) {
        int p, q;
        cin >> p >> q;
        --p;
        --q;
        int ans = 0;
        for (int j = p; j <= q; ++j) {
            ans += start_lengthLess[j][q - j];
        }
        cout << ans << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
