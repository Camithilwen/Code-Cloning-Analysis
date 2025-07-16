#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, s;
    bool truth = false;
    cin >> n >> s;
    s /= 1000;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            if (i * 9 + j * 4 + n == s)
            {
                cout << i << ' ' << j << ' ' << n - i - j;
                truth = true;
                break;
            }
        }
        if (truth == true) break;
    }
    if (truth == false) cout << "-1 -1 -1";
}