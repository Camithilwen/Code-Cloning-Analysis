#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i < m + 1; i++) {
        if (i <= m - m / 2) {
            cout << i << " " << n + 1 - i << endl;
        } else {
            cout << n + 1 - i - (m - i + 1) * 2 << " " << n + 1 - i << endl;
        }
    }
}