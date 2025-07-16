#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;
char mp[MAXN][MAXN];

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j < 100; j++, j++) {
            mp[i][j] = '.';
            if (b > 1) {
                mp[i][j + 1] = '#';
                b--;
            } else
                mp[i][j + 1] = '.';
        }
        i++;
        for (int j = 1; j <= 100; j++)
            mp[i][j] = '.';
    }
    for (int i = 51; i <= 100; i++) {
        for (int j = 1; j <= 100; j++)
            mp[i][j] = '#';
        i++;
        for (int j = 1; j < 100; j++, j++) {
            mp[i][j] = '#';
            if (a > 1) {
                mp[i][j + 1] = '.';
                a--;
            } else
                mp[i][j + 1] = '#';
        }
    }
    cout << 100 <<" "<< 100 << endl;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++)
            cout << mp[i][j];
        cout << endl;
    }
    return 0;
}