#include<bits/stdc++.h>
using namespace std;

vector< int >apply(const vector< int >&v) {
    int n = v.size();
    vector< int >cu(n, 0);
    for (int i = 0; i < n; i++) {
        int l = max(i-v[i], 0);
        int r = min(i+v[i], n-1);
        cu[l]++;
        if (r+1 < n) cu[r+1]--;
    }
    for (int i = 1; i < n; i++) cu[i] += cu[i-1];
    return cu;
}


int main() {
    int n, k;
    cin >> n >> k;

    vector< int >a(n);
    for (int &x : a) cin >> x;

    while (k--) {
        vector< int >r = apply(a);
        if (a == r) break;
        swap(a, r);
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}
