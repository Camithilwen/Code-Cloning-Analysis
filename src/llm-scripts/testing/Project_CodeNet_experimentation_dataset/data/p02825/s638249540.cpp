//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void dout() { cerr << '\n'; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << " " << H;
    dout(T...);
}

#ifdef LOCAL
    #define dbg(...) cerr << #__VA_ARGS__, dout(__VA_ARGS__)
#else
    #define dbg(...) ;
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

const int N = 1003;
char ans[4][7][7], m[N][N];
string arr[4] = {"adeeadffbbghccgh",
"adf..adf..beehhb.giiccgjj",
"adgg..adhh..beii..be..jjcf..kkcf..ll",
"adg....adg....be.ii..be.jj..cff..llc.h..mm..hkknn"
};

void parse(int r) {
    int a = 4 + r;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            ans[r][i][j] = arr[r][i * a + j];
        }
    }
}

void spread(int x, int r) {
    int a = 4 + r;
    for (int i = x; i < x + a; i++) {
        for (int j = x; j < x + a; j++) {
            m[i][j] = ans[r][i - x][j - x];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    for (int i = 0; i < 4; i++) {
        parse(i);
    }

    int n;
    cin >> n;
    if (n <= 2) {
        cout << -1;
        return 0;
    }
    if (n == 3) {
        cout << "acc\na.d\nbbd";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = '.';
        }
    }
    int rem = n % 4;
    spread(0, rem);
    int times = (n - (4 + rem)) / 4, cur = 4 + rem;
    while (times--) {
        spread(cur, 0);
        cur += 4;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j];
        }
        cout << '\n';
    }
}
