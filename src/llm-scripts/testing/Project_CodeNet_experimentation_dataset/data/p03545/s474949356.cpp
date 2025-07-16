#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep01(i, n) for(int i = 0; i < (n) + 1; i++)
#define rep10(i, n) for(int i = 1; i < (n); i++)
#define all(a) (a).begin(), (a).end()
typedef long long int ll;
using namespace std;

//ABC079C
int main()
{
    string s;
    cin >> s;

    int a[4];
    rep(i, 4) a[i] = s[i] - 48;

    char sig[3];
    rep(i, 1 << 3) {
        int sum = a[0];
        rep(bit, 3) {
            if (i & 1 << bit) {
                sum += a[bit + 1];
                sig[bit] = '+';
            }
            else {
                sum -= a[bit + 1];
                sig[bit] = '-';
            }
        }
        if (sum == 7) break;
    }

    cout << s[0] << sig[0] << s[1] << sig[1] << s[2] << sig[2] << s[3] << "=7" << endl;

    return 0;
}