#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int k, x;
    cin >> k >> x;
    int left = x - k + 1, right = x + k - 1;
    for(int i = left; i < right; i++)
        cout << i << " ";
    cout << right << endl;
    return 0;
}
