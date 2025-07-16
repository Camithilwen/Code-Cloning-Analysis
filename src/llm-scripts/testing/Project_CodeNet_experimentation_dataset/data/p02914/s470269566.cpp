#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long s = 0;
    for (long x : a) s ^= x;
    vector<long> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        b[i] = a[i] & (~s);
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    vector<long> q;
    long c = 0;
    for (long x : b) {
        for (long y : q) {
            x = min(x, x ^ y);
        }
        if (x > 0) {
            q.push_back(x);
            c = max(c, c ^ x);
        }
    }
    s += c * 2;
    cout << s;

    return 0;
}