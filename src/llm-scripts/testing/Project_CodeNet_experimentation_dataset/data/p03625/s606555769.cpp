#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}





void _main() {
        int n; cin >> n;
        map<int, int> freq;
        while (n--) {
                int a; cin >> a;
                freq[a]++;
        }

        vector<int> candidates;
        for (const auto it: freq) {
                if (it.second >= 2) candidates.emplace_back(it.first);
                if (it.second >= 4) candidates.emplace_back(it.first);
        }



        sort(all(candidates), greater<>());
        if (candidates.size() < 2) cout << 0;
        else cout << (ll) candidates[0] * candidates[1];
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
