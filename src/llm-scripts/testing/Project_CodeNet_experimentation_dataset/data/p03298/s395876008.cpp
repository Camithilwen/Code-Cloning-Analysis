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

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long int res = 0;
    for (int i = 0; i < (1 << n); i++) {
        string s1, s2;
        for (int j = 0; j < n; j++) {
            if ((i >> j) % 2 == 1) {
                s1.push_back(s[j]);
            } else {
                s2.push_back(s[j]);
            }
        }
        // reverse(s2.begin(), s2.end());

        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> v(n1 + 1, vector<int>(n2 + 1, 0));
        v[0][0] = 1;
        for (int a = 0; a <= n1; a++) {
            for (int b = 0; b <= n2; b++) {
                if (v[a][b] == 0) continue;
                if (a < n1) {
                    if (s[2 * n - 1 - a - b] == s1[a]) {
                        v[a + 1][b] += v[a][b];
                    }
                }
                if (b < n2) {
                    if (s[2 * n - 1 - a - b] == s2[b]) {
                        v[a][b + 1] += v[a][b];
                    }
                }
            }
        }
        res += v[n1][n2];
    }
    cout << res << endl;
}


