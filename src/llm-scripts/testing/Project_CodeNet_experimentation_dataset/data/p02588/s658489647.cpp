#include <bits/stdc++.h>
#define MAX 60
#define browse for (int i = 0; i < MAX; ++i) for (int j = 0; j < MAX; ++j) for (int ii = 0; ii < MAX; ++ii) for (int jj = 0; jj < MAX; ++jj)

using namespace std;

int n, cnt[MAX][MAX], a, b;
long long y, ans;
long double x;


int main() {
    cin >> n;

    while (n--) {
        cin >> x;

        y = (long long)(x * 1e9 + 0.5);
        a = 0;
        b = 0;

        while (y % 2 == 0) {
            y /= 2;
            ++a;
        }

        while (y % 5 == 0) {
            y /= 5;
            ++b;
        }

        ++cnt[a][b];
    }

    browse
        if (make_pair(i, j) <= make_pair(ii, jj) && i + ii >= 18 && j + jj >= 18) {
            if (i == ii && j == jj)
                ans += (long long) cnt[i][j] * (cnt[i][j] - 1) / 2;
            else
                ans += (long long) cnt[i][j] * cnt[ii][jj];
        }

    cout << ans;
    return 0;
}