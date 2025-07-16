#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

string solve() {
    size_t k; cin >> k;
    string s; cin >> s;
    if (s.size() > k) {
        return s.substr(0, k) + "...";
    }

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
