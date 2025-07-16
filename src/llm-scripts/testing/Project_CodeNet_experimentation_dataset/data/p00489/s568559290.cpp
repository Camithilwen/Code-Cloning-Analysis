//https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Prelim/0566?year=2012

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pt(static_cast<unsigned long>(n + 1));//各チームの得点
    for (int i = 0; i < n * (n - 1) / 2; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (c > d) {
            pt[a] += 3;
        } else if (c < d) {
            pt[b] += 3;
        } else if (c == d) {
            pt[a]++;
            pt[b]++;
        }
    }

    vector<int> vt;//順位計算用
    for (int i = 1; i <= n; ++i) {
        vt.emplace_back(pt[i]);
    }
    vt.emplace_back(100000);
    sort(vt.begin(), vt.end());

    for (int i = 1; i <= n; ++i) {
        auto tmp = upper_bound(vt.begin(), vt.end(), pt[i]);
        cout << n + 1 - (tmp - vt.begin()) << endl;
    }
    return 0;
}

/*
 *
 */
