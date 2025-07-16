#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    int left = l;
    int right = l + n - 1;
    int eat = 0;
    if (left >= 0) {
        eat = left;
    } else if (right <= 0) {
        eat = right;
    } else {
        eat = 0;
    }
    int ans = ((left + right) * n / 2) - eat;
    cout << ans << endl;
    return 0;
}
