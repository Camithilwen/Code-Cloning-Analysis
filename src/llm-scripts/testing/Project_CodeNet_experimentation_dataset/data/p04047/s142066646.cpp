#include <bits/stdc++.h>
using namespace std;


int N;
int main() {
    cin >> N;
    vector<int> v;
    for (int i =0 ;i < 2 * N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i =0 ;i < N; i++) {
        ans += v[2 * i];
    }
    cout << ans << '\n';
}
