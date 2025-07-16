#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i,n) cin >> a[i+1];
    vector<int> ans(n+1);
    for (int i = n; i >= 1; i--) {
        int cnt = 0;
        for (int j = i; j <= n; j += i) {
            cnt += ans[j];
        }
        ans[i] = a[i]^(cnt%2);
    }
    int b = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i]) b++;
    }
    cout << b << endl;
    for (int i = 1; i <= n; i++) {
        if (ans[i]) cout << i << endl;
    }
    return 0;
}