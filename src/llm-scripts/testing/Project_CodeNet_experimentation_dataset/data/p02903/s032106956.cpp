#include <bits/stdc++.h>
#define pb push_back
#define pll pair <ll, ll>
#define mp make_pair
#define pyshnapyshnakaa ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define x first
#define y second
#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#define plll pair <ll, pair <ll, ll>>
#define pllll pair <pair <ll, ll>, pair <ll, ll> >
#define psl pair <string, ll>
#define all(a) a.begin(), a.end()
#define vvl vector <vector <ll> >

typedef long long ll;

typedef long double ld;

using namespace std;

const ll maxn = 1e3 + 10;

ll n, m, k, t;

ll x, y;

ll ANS[maxn][maxn];

int main() {
    pyshnapyshnakaa;
    ll q, w, e, a, b, c;
    cin >> n >> m >> x >> y;
    for (q = 0; q < n; q++) {
        for (w = 0; w < x; w++) {
            ANS[q][w] = 0;
        }
        for (w = x; w < m; w++) {
            ANS[q][w] = 1;
        }
    }
    for (q = 0; q < y; q++) {
        for (w = 0; w < m; w++) {
            ANS[q][w] ^= 1;
        }
    }
    for (q = 0; q < n; q++) {
        for (w = 0; w < m; w++) {
            cout << ANS[q][w];
        }
        cout << endl;
    }
    return 0;
}
