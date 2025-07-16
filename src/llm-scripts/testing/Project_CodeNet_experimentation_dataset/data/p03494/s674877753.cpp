#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200, MAXINT=2147483647;
int a[N], t, n, mi=MAXINT;
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i]%2) {
            cout << 0; return 0;
        } else {
            int tp=0;
            while (!(a[i]%2)) {
                a[i]/=2; tp++;
            }
            if (tp<mi) mi=tp;
        }
    }
    
    cout << mi;
}