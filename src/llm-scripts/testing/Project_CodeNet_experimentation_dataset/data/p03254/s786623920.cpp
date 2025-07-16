#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x, res = 0;
    cin >> N >> x;

    int a[N];

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a, a+N);

    for (int j = 0; j < N; j++) {
        if (j == N -1) {
            if (x == a[j]) {
                res++;
            }
            break;
        }
        if (x - a[j] >= 0) {
            x -= a[j];
            res++;
        }
    }

    cout << res << endl;
}