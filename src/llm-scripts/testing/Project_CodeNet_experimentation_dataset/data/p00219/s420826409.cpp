#include <bits/stdc++.h>
#define endl    '\n'
using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, c;

    cin >> n;

    while (n != 0) {
        int hist[10] = {};

        for (int i = 0; i < n; ++i) {
            cin >> c;

            hist[c]++;
        }

        for (int i = 0; i < 10; i++) {
            if (hist[i] == 0) {
                cout << "-" << endl;
            } else {
                for (int j = 0; j < hist[i]; ++j) {
                    cout << "*";
                }
                cout << endl;
            }
        }

        cin >> n;
    }

    return 0;
}


