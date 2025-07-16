#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n; int64_t ans = 0;
    vector<int64_t> a(n), b(n);
    priority_queue<pair<int64_t, int>> que;
    for (auto i = 0; i < n; i++) {
        cin >> a[i] >> b[i]; que.push({{a[i] + b[i]}, i});
    }
    for (auto i = 0; i < n; i++) {
        auto p = que.top(); que.pop();
        if(i % 2 == 0) ans += a[p.second];
        else ans -= b[p.second];
    }
    cout << ans << endl;
    return 0;
}