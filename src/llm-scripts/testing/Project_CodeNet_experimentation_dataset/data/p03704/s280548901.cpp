#include <bits/stdc++.h>

using namespace std;
using ll=long long ;

int D;

int res = 0;
ll pw[19];
int digit[19];

void dfs(int high, int low, ll dif, ll way, bool carry) {
    if (high < low) {
        if (dif == D) res += way;
    } else if(high == low) {
        dfs(high-1, low+1, dif, way*10, 0);
    } else {
        int d = digit[low] + carry; carry = 0;
        if (d == 10) d = 0, carry = 1;
        dfs(high-1, low+1, dif + (pw[low] - pw[high])*d, way*(10-d-(low==0 && d==0)), carry);
        if (d > 0) {
            dfs(high-1, low+1, dif + (pw[low] - pw[high])*(d-10), way*(d - (low==0)), 1);
        }
    }
}

void solve() {
    cin >> D;
    pw[0] = 1;
    for (int i = 1; i <= 18; i++) {
        pw[i] = 10*pw[i-1];
    }
    ll x = D;
    for (int i = 0; i <= 18; i++) {
        digit[i] = x%10;
        x/=10;
    }
    for (int len = 1; len <= 18; len++) {
        dfs(len-1, 0, 0, 1, 0);
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout << endl;
}
