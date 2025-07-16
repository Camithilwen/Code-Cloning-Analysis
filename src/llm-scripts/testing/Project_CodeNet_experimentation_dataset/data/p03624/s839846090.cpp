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
    vector<bool> flg(26, false);
    int n = s.size();
    rep(i, n) flg[s[i] - 'a'] = true;
    rep(i, 26) {
        if (!flg[i]) {
            cout << (char)(i + 'a') << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}
