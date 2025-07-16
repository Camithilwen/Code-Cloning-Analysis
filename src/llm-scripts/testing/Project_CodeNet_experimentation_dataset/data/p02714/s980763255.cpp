#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const int INF = 1000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> c(n);
    vector<int> r_num(n + 1, 0);
    vector<int> g_num(n + 1, 0);
    vector<int> b_num(n + 1, 0);
    rep(i, n) {
        r_num[i + 1] = r_num[i];
        g_num[i + 1] = g_num[i];
        b_num[i + 1] = b_num[i];
        if (s[i] == 'R') {
            c[i] = 0;
            r_num[i + 1] = r_num[i] + 1;
        }
        else if (s[i] == 'G') {
            c[i] = 1;
            g_num[i + 1] = g_num[i] + 1;
        }
        else {
            c[i] = 2;
            b_num[i + 1] = b_num[i] + 1;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i + 1; j < n-1; j++) {
            if (c[i] == c[j]) continue;
            if (c[i] + c[j] == 1) {  // RGのとき
                ans += b_num[n] - b_num[j + 1];
                if (2*j - i < n) {
                    if (c[2 * j - i] == 2) ans -= 1;
                }
            }
            else if (c[i] + c[j] == 3) {  // GBのとき
                ans += r_num[n] - r_num[j + 1];
                if (2 * j - i < n) {
                    if (c[2 * j - i] == 0) ans -= 1;
                }
            }
            else {  // RBのとき
                ans += g_num[n] - g_num[j + 1];
                if (2 * j - i < n) {
                    if (c[2 * j - i] == 1) ans -= 1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}