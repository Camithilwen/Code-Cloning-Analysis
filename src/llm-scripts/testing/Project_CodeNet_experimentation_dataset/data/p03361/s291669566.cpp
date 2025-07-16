#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    rep(i, H) cin >> s[i];
    
    rep(y, H) rep(x, W) {
        if (s[y][x] != '#') {
            continue;
        }
        bool ok =false;
        rep(i, 2) {
            int xx = x - 1 + 2 * i;
            int yy = y;
            if (0 <= xx && xx < W && 0 <= yy && yy < H) {
                if (s[yy][xx] == '#') {
                    ok = true;
                }
            }
        }
        rep(i, 2) {
            int xx = x;
            int yy = y - 1 + 2 * i;
            if (0 <= xx && xx < W && 0 <= yy && yy < H) {
                if (s[yy][xx] == '#') {
                    ok = true;
                }
            }
        }
        if (ok == false) {
            put("No");
            return 0;
        }
    }

    put("Yes");

    return 0;
}