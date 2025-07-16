#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    int ai = 0;
    int bi = 0;
    int ci = 0;
    char x = 'a';
    char ans = '\0';
    while (1) {
        switch (x) {
            case 'a':
                if (ai == a.size()) {
                    cout << 'A';
                    return 0;
                }
                x = a[ai];
                ai++;
                break;
            case 'b':
                if (bi == b.size()) {
                    cout << 'B';
                    return 0;
                }
                x = b[bi];
                bi++;
                break;
            case 'c':
                if (ci == c.size()) {
                    cout << 'C';
                    return 0;
                }
                x = c[ci];
                ci++;
                break;
        }
    }
}
