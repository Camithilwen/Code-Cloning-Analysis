
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int cur = 1;
    while (n) {
        cur = min(cur * 2, cur + k);
        --n;
    }
    cout << cur << endl;

    return 0;
}

