#include <iostream>
#include <map>

using namespace std;

#define MN 101

int n;
int ks[MN];
string raw;

map<char, int> kmap;
map<int, char> rkmap;

void init_() {
    for (char i = 'a'; i <= 'z'; i++) {
        kmap[i] = i - 'a';
        rkmap[i - 'a'] = i;
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        kmap[i] = i - 'A' + 26;
        rkmap[i - 'A' + 26] = i;
    }
}

bool init() {
    cin >> n;
    if (n == 0) return false;
    for (int i = 0; i < n; i++) {
        cin >> ks[i];
    }
    cin >> raw;
    return true;
}

char before(char r, int b) {
    int i = kmap[r];
    return rkmap[(i + 52 - b) % 52];
}

void solve() {
    string ans = raw;
    int kindex = 0;
    for (int i = 0; i < raw.size(); i++) {
        ans[i] = before(raw[i], ks[kindex]);
        kindex = (kindex + 1 + n) % n;
    }
    cout << ans << endl;
}

int main() {
    init_();
    while (init()) {
        solve();
    }
    return 0;
}