#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

bool f(const vector<int>& v1, const vector<int>& v2) {
    int c1 = accumulate(v1.begin(), v1.end(), 0);
    int c2 = accumulate(v2.begin(), v2.end(), 0);
    if (c1 < c2) return false;
    if (c1 > c2) return true;
    c1 = 0, c2 = 0;
    for (int i = 9; i >= 0; i--) {
        c1 += v1[i];
        c2 += v2[i];
        if (c1 > c2) return true;
        if (c1 < c2) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v = {0,2,5,5,4,5,6,3,7,6};
    vector<pair<int, int>> vp;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        vp.push_back(make_pair(v[a], -a));
    }
    sort(vp.begin(), vp.end());
    for (int i = 0; i < m; i++) {
        vp[i].second *= -1;
    }
    vector<vector<vector<int>>> res(m, vector<vector<int>>(n + 1, vector<int>(0)));
    vector<int> base(10, 0);
    for (int i = 0; i * vp[0].first <= n; i++) {
        base[vp[0].second] += i;
        res[0][n - i * vp[0].first] = base;
        base[vp[0].second] = 0;
    }
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j <= n; j++) {
            if (res[i][j].size() == 0) continue;
            vector<int> digit = res[i][j];
            
            for (int k = j / vp[i + 1].first; k >= 0; k--) {
                int remain = j - k * vp[i + 1].first;
                digit[vp[i + 1].second] += k;
                if (res[i + 1][remain].size() == 0 || f(digit, res[i + 1][remain])) {
                    res[i + 1][remain] = digit;
                }
                digit[vp[i + 1].second] -= k;
            }
        }
    }
    string s;
    for (int i = 0; i < 10; i++) {
        s += string(res[m - 1][0][i], i + '0');
    }
    sort(s.begin(), s.end(), greater<char>());
    cout << s << endl;
}
