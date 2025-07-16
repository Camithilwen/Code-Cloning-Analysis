#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
const int N = 1e4+10;

string dp[N], val[15];
string num = "123456789";
int c[] = {2,5,5,4,5,6,3,7,6}, cs[200], n, m;
string a[15];

void update (string &x, string y, string z)
{
    if (x.size() > y.size() + 1) return;
    if (z[0] > y[0]) z += y, swap(y, z);
    else y += z;
    if (x.size() < y.size()) x = y;
    else
    {
        for (int i=0; i<x.size(); i++)
        {
            if (x[i] > y[i]) return;
            else if (x[i] < y[i])
            {
                x = y;
                break;
            }
        }
    }
}

signed main()
{
    XinAi
    for (int i=0; i<9; i++) cs[num[i]] = c[i];
    cin >> n >> m;
    for (int i=0; i<m; i++) cin >> a[i];
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            if (i!=0 && dp[i]=="") continue;
            update(dp[i+cs[a[j][0]]], dp[i], a[j]);
        }
    cout << dp[n] << '\n';
}
