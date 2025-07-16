#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e5 + 5;
int a[NMAX], sol, n, m, s;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x]++;
        a[y + 1]--;
    }
    for(int i = 1; i <= n; i++) {
        s += a[i];
        if(s == m) {
            sol++;
        }
    }
    cout << sol;
    return 0;
}
