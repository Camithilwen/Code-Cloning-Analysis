#include <iostream>
#include <iomanip>
#include <string>

typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for(ll i=init;i<(n);i++)

int main() {
    string s;
    cin >> s;

    if (s == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
        return 0;
    }

    bool c[26] = {false};
    int n = s.size();
    repi(i, n, 0) {
        c[s[i] - 'a'] = true;
    }
    if (n == 26) {
        for (int i = n - 1; i >= 0; i--) {
            bool flag = false;
            repi(j, 26, s[i] - 'a') {
                if (!c[j]) {
                    if (i + 1 != n) {
                        s.erase(i);
                    }
                    s.push_back('a' + j);
                    flag = true;
                    break;
                }
            }
            if (flag)break;
            c[s[i] - 'a'] = false;
            s.erase(i);
        }
    } else {
        for (int i = n - 1; i >= 0; i--) {
            bool flag = false;
            repi(j, 26, 0) {
                if (!c[j]) {
                    s.push_back('a' + j);
                    flag = true;
                    break;
                }
            }
            if (flag)break;
        }
    }

    cout << s << endl;
    return 0;
}