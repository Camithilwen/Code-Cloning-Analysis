#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, a[200005] = {}, b[200005] = {}, c[600005] = {}, d[600005] = {};
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    a[n] = a[0]; b[n] = b[0];
    for (int i = 0; i < n; i++) c[i] = b[i] ^ b[i + 1];
    c[n] = -1;
    for (int i = n + 1; i <= n + n; i++) c[i] = a[i - n - 1] ^ a[i - n];
    for (int i = n + n + 1; i <= n + n + n; i++) c[i] = c[i - n];
    for (int i = 1; i <= n + n + n + 1; i++) {
        int x = i - 1;
        while (x && d[x] != i - 1 && c[d[x]] != c[i - 1]) x = d[x];
        if (x) d[i] = d[x] + 1;
    }
    for (int i = n + n + 1; i <= n + n + n; i++) if (d[i] == n) cout << i - n - n - 1 << ' ' << (a[i - n - n - 1] ^ b[0]) << '\n';
}
