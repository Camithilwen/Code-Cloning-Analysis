#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    int min = INT32_MAX;
    int flavor = 0;
    for (int i = 1; i <= n; ++i) {
        if (abs(i + l - 1) < abs(min)) {
            min = i + l - 1;
        }
        flavor += i + l - 1;
    }
    flavor -= min;
    cout << flavor << '\n';
}