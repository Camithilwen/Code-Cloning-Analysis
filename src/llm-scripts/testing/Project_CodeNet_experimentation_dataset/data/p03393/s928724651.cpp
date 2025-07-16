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
    int n = s.size();
    if (n != 26) {
        vector<bool> flg(26, false);
        rep(i, n) flg[s[i]-'a'] = true; 
        cout << s;
        rep(i, 26) {
            if (!flg[i]) {
                cout << (char)(i + 'a') << endl;
                return 0;
            }
        }
    }
    else {
        string t = s;
        if (!next_permutation(t.begin(), t.end())) {
            cout << -1 << endl;
            return 0;
        }
        rep(i, n) {
            cout << t[i];
            if (t[i] != s[i]) {
                cout << endl;
                break;
            } 
        }
    }
    return 0;
}
