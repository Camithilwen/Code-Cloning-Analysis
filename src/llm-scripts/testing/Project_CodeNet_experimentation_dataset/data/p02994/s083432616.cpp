#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    int pie = l*n - n;
    for (int i = 1; i <= n; i++) {
        pie += i;
    }

    if (l < 0) {
        if (n-1 < abs(l)) pie -= l+n-1;
    }
    else {
        pie -= l;
    }

    cout << pie << endl;
}