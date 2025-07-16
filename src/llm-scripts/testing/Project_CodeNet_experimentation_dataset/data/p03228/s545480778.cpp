#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, k; cin >> a >> b >> k;
    for (int i=0; i<k; ++i) {
        int na, nb;
        if (i%2 == 0) {
            na = a/2;
            nb = b + a/2;
        } else {
            nb = b/2;
            na = a + b/2;
        }
        a = na;
        b = nb;
    }
    cout << a << " " << b << endl;
}