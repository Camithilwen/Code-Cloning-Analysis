#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    rep(i,t) cin >> a[i];
    sort(all(a));
    int mx = a[t-1];
    int e = k-mx;
    if(mx-1 <= e) cout << 0 << endl;
    else cout << mx-1-e << endl;
    return 0;
}