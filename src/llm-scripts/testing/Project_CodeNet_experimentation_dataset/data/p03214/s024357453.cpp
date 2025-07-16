#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    double average = (double)accumulate(a.begin(), a.end(), 0)/n;
    int ans = 0;
    double minv=100100100;
    rep(i, n) {
        if (abs(average-(double)a[i])< minv) {
            ans = i;
            minv = abs(average-(double)a[i]);
        }
    }
    cout << ans << endl;
    //cout << a[ans] << endl;
}
