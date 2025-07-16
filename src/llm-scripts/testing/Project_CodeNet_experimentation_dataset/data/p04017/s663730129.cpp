#include <bits/stdc++.h>

using namespace std;

#define loop(i, n) for(int i = 0;i < int(n);i++)
#define rloop(i, n) for(int i = int(n);i >= 0;i--)
#define range(i, a, b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1, v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1, v2, v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1, v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1, v2, v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define endl '\n'

typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
const int LG = 18;
int up[N][LG];
int arr[N];
int n, l, q;

void run_case() {
    cin >> n;
    loop(i, n)cin >> arr[i];
    cin >> l >> q;

    rloop(i, n - 1) {
        int par = i == n - 1 ? n - 1 : (upper_bound(arr + i, arr + n, arr[i] + l) - arr - 1);
        up[i][0] = par;
        for (int k = 1; k < LG; ++k)
            up[i][k] = up[up[i][k - 1]][k - 1];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a > b)swap(a, b);
        int ans = 1;
        for (int i = LG - 1; i >= 0; i--) {
            if (up[a][i] < b) {
                a = up[a][i];
                ans += 1 << i;
            }
        }
        cout << ans << endl;
    }
}

int main() {

#ifndef ONLINE_JUDGE
//    freopen("in.in", "r", stdin);
//    freopen("out.in", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T = 1;
//    cin >> T;
    while (T--)run_case();

    return 0;
}
