#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    string s;
    cin >> s;
    rep(i, 1<<3) {
        int num = s[0] - '0';
        string ans = "";
        ans += s[0];
        rep(j, 3) {
            if ((i>>j) & 1) {
                //cout << s[j+1] - '0' << endl;
                num += (s[j+1] - '0');
                ans += '+';
                ans += s[j+1];
            }
            else {
                //cout << s[j+1] - '0' << endl;
                num -= (s[j+1] - '0');
                ans += '-';
                ans += s[j+1];
            }
            //cout << num << endl;
            //cout << ans << endl;
        }
        if (num == 7) {
            cout << ans << "=7" << endl;
            return 0;
        }
    }
    return 0;
}
