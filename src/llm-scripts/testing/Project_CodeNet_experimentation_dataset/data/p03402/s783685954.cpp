#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int wh, bk; cin >> wh >> bk;
    int h = 100 / 2, w = 100;
    cout << h * 2 << " " << w << endl;
    auto func = [&](char c0, char c1, int cnt) {
        vector<string> s(h, string(w, c0));
        for (int i = 1; i < h - 1; i += 2) for (int j = 0; j < w; j += 2) {
            if (cnt) s[i][j] = c1, cnt--;
        }
        for (auto &si: s) cout << si << endl;
    };
    func('.', '#', bk - 1);
    func('#', '.', wh - 1);
    return 0;
}
