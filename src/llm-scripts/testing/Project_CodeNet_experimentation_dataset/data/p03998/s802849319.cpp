#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    vector<string> vec(3);
    rep(i, 3) {
        cin >> vec[i];
        vec[i] += 'z';
    }
    vector<int> card_idx(3, 0);
    int player = 'a' - 'a';
    char now = vec[player][card_idx[player]];
    card_idx[player] += 1;
    while (now != 'z') {
        player = now - 'a';
        now = vec[player][card_idx[player]];
        card_idx[player] += 1;
    }
    cout << (char)('A' + player) << endl;
    return 0;
}