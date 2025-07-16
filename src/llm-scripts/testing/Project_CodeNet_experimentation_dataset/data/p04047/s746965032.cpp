#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n+n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    while(v.size() > 0) {
        v.pop_back();
        ans += v.back();
        v.pop_back();
    }
    cout << ans << endl;

    return 0;
}

