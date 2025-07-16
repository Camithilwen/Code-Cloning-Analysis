#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    int *p = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int cnt = 0;
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (p[i] <= min) {
            min = p[i];
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}