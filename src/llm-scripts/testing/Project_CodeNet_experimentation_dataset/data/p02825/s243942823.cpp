#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

vector<string> three = {
    "add",
    "a.c",
    "bbc",
};

vector<string> four = {
    "afgg",
    "afhh",
    "bbde",
    "ccde",
};

vector<string> five = {
    "ahhii", "ag..j", "bg..j", "b.ffe", "ccdde",
};

vector<string> six = {
    "aa.bbc", "de...c", "deff..", "..gghi", "j...hi", "jkk.ll",
};

vector<string> seven = {
    "a.jj.kk", "ai..ll.", ".i.mm.o", "b.h...o", "b.h..g.", ".ff..ge", "cc.dd.e",
};

int n;

// 4,5,6,7
void solve(int a, int b, int c, int d) {
    vector<string> ans(n, string(n, '.'));
    int id = 0;
    for(int i = 0; i < a; i++) {
        for(int y = id; y < id + 4; y++) {
            for(int x = id; x < id + 4; x++) {
                ans[y][x] = four[y - id][x - id];
            }
        }
        id += 4;
    }
    for(int i = 0; i < b; i++) {
        for(int y = id; y < id + 5; y++) {
            for(int x = id; x < id + 5; x++) {
                ans[y][x] = five[y - id][x - id];
            }
        }
        id += 5;
    }
    for(int i = 0; i < c; i++) {
        for(int y = id; y < id + 6; y++) {
            for(int x = id; x < id + 6; x++) {
                ans[y][x] = six[y - id][x - id];
            }
        }
        id += 6;
    }
    for(int i = 0; i < d; i++) {
        for(int y = id; y < id + 7; y++) {
            for(int x = id; x < id + 7; x++) {
                ans[y][x] = seven[y - id][x - id];
            }
        }
        id += 7;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    if(n <= 2) {
        cout << -1 << endl;
        return 0;
    }
    if(n == 3) {
        for(int i = 0; i < three.size(); i++) {
            cout << three[i] << endl;
        }
        return 0;
    }
    for(int i = 0; i * 7 <= n; i++) {
        for(int j = 0; j * 6 <= n; j++) {
            for(int k = 0; k * 5 <= n; k++) {
                int sum = i * 7 + j * 6 + k * 5;
                if(sum <= n && (n - sum) % 4 == 0) {
                    int l = (n - sum) / 4;
                    solve(l, k, j, i);
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
}