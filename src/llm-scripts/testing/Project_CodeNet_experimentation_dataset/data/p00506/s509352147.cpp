#include <iostream>
using namespace std;

int main() {
        long long h[4];
        int a, b, c, ab, cc;
        int i, n;
        long long j, minl, amari;

        cin >> n;
        for (i = 0; i < n; i++) {
                cin >> h[i];
        }
        minl = h[0];
        for (i = 1; i < n; i++) {
                if (minl > h[i]) minl = h[i];
        }

        for (j = 1; j <= minl; j++) {
                amari = 0;
                for (i = 0; i < n; i++) {
                        amari += h[i] % j;
                }
                if (amari == 0) cout << j << endl;
        }
        return 0;
}

