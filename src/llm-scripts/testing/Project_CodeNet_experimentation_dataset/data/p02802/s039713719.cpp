#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> wa(N + 5, 0);
    for (int i = 0; i < M; i++) {
        int p;
        string s;
        cin >> p >> s;
        if (wa[p] >= 0 && s == "WA") wa[p]++;
        else if (wa[p] >= 0 && s == "AC") wa[p] = wa[p] * (-1) - 1;
    }
    int ac = 0, penalty = 0;
    for (auto a: wa){
        if (a < 0) {
            penalty += (a + 1) * (-1);
            ac++;
        }
    }
    cout << ac << " " << penalty << endl;
    return 0;
}