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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    vector<string> g(100);
    for(int i = 0; i < 100; i++) {
        string tmp = "";
        if(i < 50) {
            for(int j = 0; j < 100; j++) {
                tmp += "#";
            }
        } else {
            for(int j = 0; j < 100; j++) {
                tmp += ".";
            }
        }
        g[i] = tmp;
    }
    int h = 0, w = 1;
    while(a - 1 > 0) {
        if(w == 99) {
            h += 2;
            w = 1;
        }
        g[h][w] = '.';
        w += 2;
        a--;
    }
    h = 51, w = 1;
    while(b - 1 > 0) {
        if(w == 99) {
            h += 2;
            w = 1;
        }
        g[h][w] = '#';
        w += 2;
        b--;
    }
    cout << "100 100" << endl;
    for(int i = 0; i < 100; i++) {
        cout << g[i] << endl;
    }
}