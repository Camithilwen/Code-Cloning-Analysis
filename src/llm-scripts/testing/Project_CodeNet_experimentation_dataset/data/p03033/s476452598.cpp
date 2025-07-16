#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> s(n), t(n), x(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i] >> x[i];
    }

    vector<pair<int, int>> sx(n), tx(n);
    for (int i = 0; i < n; i++) {
        sx[i] = make_pair(s[i] - x[i], x[i]);
        tx[i] = make_pair(t[i] - x[i], x[i]);
    }

    sort(sx.begin(), sx.end());
    sort(tx.begin(), tx.end());

    multiset<int> u;
    vector<pair<int, int>>::iterator isx = sx.begin(), itx = tx.begin();

    for (int i = 0; i < q; i++) {
        int d;
        cin >> d;

        for (; isx != sx.end() && isx->first <= d; isx++) {
            u.insert(isx->second);
        }
        for (; itx != tx.end() && itx->first <= d; itx++) {
            u.erase(u.lower_bound(itx->second));
        }

        cout << (u.size() == 0 ? -1 : *u.begin()) << endl;
    }
}
