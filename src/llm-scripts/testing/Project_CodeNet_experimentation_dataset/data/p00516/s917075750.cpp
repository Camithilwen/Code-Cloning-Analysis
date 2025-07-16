#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

int main() {
    int n, m, a[1001], b[1001];
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int r[1001] = {};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j] <= b[i]) {
                r[j]++;
                break;
            }
        }
    }

    int max = 0;
    int maxI = 0;
    for (int k = 0; k < n; ++k) {
        if (max < r[k]) {
            max = r[k];
            maxI = k;
        }
    }

    cout << maxI + 1 << endl;

    return 0;
}