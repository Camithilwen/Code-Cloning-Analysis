#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<pair<int, int>> pos, neg;
    REP(i, 0, N) {
        string s; cin >> s;
        int lowest = 0, inc = 0;
        for (auto c : s) {
            if (c == '(') {
                inc++;
            } else {
                inc--;
                lowest = min(lowest, inc);
            }
        }
        if (inc > 0) pos.push_back({lowest, inc});
        else neg.push_back({lowest - inc, -inc});
    }

    sort(ALL(pos), greater<pair<int, int>>());
    sort(ALL(neg), greater<pair<int, int>>());

    int curp = 0, curn = 0;
    for (auto p : pos) {
        if (curp + p.first < 0) {
            cout << "No" << endl;
            return 0;
        }
        curp += p.second;
    }
    for (auto n : neg) {
        if (curn + n.first < 0) {
            cout << "No" << endl;
            return 0;
        }
        curn += n.second;
    }

    if (curp == curn) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}