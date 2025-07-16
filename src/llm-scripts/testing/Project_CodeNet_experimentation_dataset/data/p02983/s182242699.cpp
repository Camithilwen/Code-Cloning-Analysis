#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
vector<int> v;
int x, y, res(2019);
int main() {
    DAU
    cin >> x >> y;
    for (int i = x; i <= min(x + 2020, y); ++i)
        v.emplace_back(i % 2019);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (size_t i = 0; i < v.size(); ++i)
        for (size_t j = i + 1; j < v.size(); ++j)
            res = min(res, (v[i] * v[j]) % 2019);
    cout << res;
    PLEC
}
