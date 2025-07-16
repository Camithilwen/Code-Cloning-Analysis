#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-8L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
#define int ll
int costs(int now) {
    for (int i = 0; i < 62; ++i) {
        if (now < (1 << i)) {
            return i + 1;
        }
    }
}

int secret_d = 10;
int n;

int interact(int a) {
    int ans = 0;
    cout << "? " << a << endl;
    if (true) {
        int r = 1;
        for (int i = 0; i < 60; ++i) {
            if ((secret_d & (1LL << i))) {
                ans += costs(r) * costs(a);
                r = r * a % n;                
            }
            ans += costs(a) * costs(a);
            a = a * a % n;
        }
    }
    else {
        cin >> ans;
    }
    return ans;
}

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}

long double comb(int a, int b) {
    ld ans = 1;
    for (int q = 0; q < b; ++q) {
        ans *= (ld)(a - q);
        ans /= (ld)(q + 1);
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> inputs;
    int ans = 0;
    REP(i, n) {
        int a;
        cin >> a;
        inputs.push_back(a);
    }
    if (inputs[0] != 0) {
        cout << -1 << endl;
        return;
    }
    for (int q = 1; q < n; ++q) {
        if (inputs[q] > inputs[q - 1] + 1) {
            cout << -1 << endl;
            return;
        }
        if (inputs[q] == inputs[q - 1] + 1) {
            ans++;
        }
        else {
            ans += inputs[q];
        }
    }
    cout << ans << endl;
}

#undef int
int main() {
    init();
    solve();
}