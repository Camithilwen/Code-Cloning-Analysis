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
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (k > *max_element(v.begin(), v.end())) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int g = v[0];
    int flag = 0;
    for (int i = 1; i < n; i++) {
        g = gcd(g, v[i]);
        if (v[i] == k) flag = 1;
    }
    if (abs(v[0] - k) % g == 0) flag = 1;
    if (flag) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
