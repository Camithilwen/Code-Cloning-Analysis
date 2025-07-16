#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int n;
    cin >> n;

    int now = 1;

    for (int i = 1; i < n; i++) {
        if (i * i > n) {
            break;
        }

        now = i * i;
    }

    cout << now << endl;
    return 0;
}