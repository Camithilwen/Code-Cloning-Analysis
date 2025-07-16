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
int dp[N][2][2];
int vis[N][2][2], visid;
int F, L;
string str;
int n;
//sheep 0 , wolf 1

int solve(int idx, int cur, int lst) {
    int &ret = dp[idx][cur][lst];
    if (vis[idx][cur][lst] == visid)return ret;
    vis[idx][cur][lst] = visid;
    if (idx == n - 1) {
        if (cur != L)return ret = 0;
        if (cur == 0) {
            ret = (str[idx] == 'o' && F == lst || str[idx] == 'x' && F != lst);
        } else {
            ret = (str[idx] == 'x' && F == lst || str[idx] == 'o' && F != lst);
        }
        return ret;
    }

    int nxt;
    if (cur == 0) {
        //truth
        nxt = (str[idx] == 'o') ? lst : (!lst);
        ret = solve(idx + 1, nxt, cur);
    } else {
        //lie
        nxt = (str[idx] == 'o') ? (!lst) : lst;
        ret = solve(idx + 1, nxt, cur);
    }
    return ret;
}

string ans;

void build(int idx, int cur, int lst) {
    ans += (cur ? 'W' : 'S');
    if (idx == n - 1)return;
    int nxt;
    if (cur == 0) {
        //truth
        nxt = (str[idx] == 'o') ? lst : (!lst);
        build(idx + 1, nxt, cur);
    } else {
        //lie
        nxt = (str[idx] == 'o') ? (!lst) : lst;
        build(idx + 1, nxt, cur);
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    //freopen("out.in", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> str;

    loop(f, 2) {
        loop(l, 2) {
            F = f, L = l;
            visid++;
            if (solve(0, f, l)) {
                build(0, f, l);
                cout << ans << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
