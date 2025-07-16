#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;
int a[4];

int main() {
    cin >> s;
    forn(i, 4) a[i] = s[i] - '0';
    forn(mask, 16) if (!(mask & 1)) {
        int res = 0;
        forn(j, 4) if (mask & (1 << j)) {
            res -= a[j];
        } else {
            res += a[j];
        }
        if (res == 7) {
            cout << a[0];
            for (int i = 1; i < 4; ++i) if (mask & (1 << i)) {
                cout << '-' << a[i];
            } else {
                cout << '+' << a[i];
            }
            cout << "=7" << endl;
            break;
        }
    }
    return 0;
}
