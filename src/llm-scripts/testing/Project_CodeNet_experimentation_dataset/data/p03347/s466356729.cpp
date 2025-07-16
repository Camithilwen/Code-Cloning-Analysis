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
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (v[0] > 0) {
        cout << -1 << endl;
        return 0;
    }
    long long int res = 0;
    int last = 0;
    for (int i = 1; i < n; i++) {

        if (v[i] == 0) {
            last = 0;
            continue;
        }
        last++;
        if (last < v[i]) {
            cout << -1 << endl;
            return 0;
        }
        if (v[i] - v[i - 1] >= 2) {
            cout << -1 << endl;
            return 0;
        }
        if (v[i] >= 2 && v[i - 1] == 0) {
            cout << -1 << endl;
            return 0;
        }
        if (v[i] == v[i - 1] + 1) {
            res++;
            continue;
        }
        res += v[i];
    }
    cout << res << endl;
}
