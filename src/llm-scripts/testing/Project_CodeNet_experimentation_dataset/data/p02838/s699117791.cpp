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
    int n;
    ll a[300005] = {}, z = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 60; i++) {
        ll b = 0;
        for (int j = 0; j < n; j++) if (a[j] & (1ll << i)) b++;
        z = (z + (1ll << i) % mod * b % mod * (n - b)) % mod;
    }
    cout << z;
}
