#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int x, y;
    cin >> x >> y;


    vector <int> c;
    c.app(x);
    c.app(-x);
    c.app(y);
    c.app(-y);

    const int INF = 5e18;
    vector <int> d(4, INF);
    d[0] = 0;

    for (int t = 0; t < 10; ++t) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (c[i] <= c[j])
                    d[j] = min(d[j], d[i] + c[j] - c[i]);
                if (c[j] == -c[i])
                    d[j] = min(d[j], d[i] + 1);
            }   
        }   
    }

    cout << d[2] << endl;
}