#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++) cin >> l[i] >> r[i];
    
    sort (l.begin(), l.end());
    sort (r.begin(), r.end());
    
    int ans = r[0] - l[m-1] + 1;
    ans = max (ans, 0);

    cout << ans << endl;
}