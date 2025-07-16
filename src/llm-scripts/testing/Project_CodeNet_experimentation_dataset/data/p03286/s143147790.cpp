#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define pb push_back
#define mp make_pair
#define ff first
#define INF LLONG_MAX
#define ss second
#define range(x) (x).begin(), (x).end()

#define vll vector<ll>
#define vstr vector<string>
#define vvll vector<vector<ll>>
#define vp vector<pll>
#define vvp vector<vp>

#define mapll map<ll, ll>
#define mapstr smap<string, ll>
#define setll set<ll>
#define setstr set<string>

#define digits(N) floor(log10(N)) + 1
const ll mod = 1e9 + 7;

#define FLUSH fflush(stdout)
#define arr1d_debug(arr, i, ans) \
    cout << #arr << '[' << i << "] = " << ans << ' ' << flush
#define arr2d_debug(arr, i, j, ans) \
    cout << #arr << '[' << i << ']' << '[' << j << "] = " << ans << ' ' << flush
#define debug1(x) \
    cout << #x << " = " << x << endl
#define debug2(x, y) \
    cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) \
    cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define newline cout << endl

#define print_container(container) \
    for (auto &it : container)     \
        cout << it << ' ';         \
    newline;

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
/*
    std : merge, rotate, unique, generate, fill, iota
*/
ll ll_scan()
{
    ll x;
    cin >> x;
    return x;
}
string str_scan()
{
    string x;
    cin >> x;
    return x;
}

ll inefficiency(ll x, ll y, vvll &prefix_table)
{
    ll ans = 0;
    for (ll i = 0; i < 101; i++)
    {
        ll temp = prefix_table[y + 1][i] - prefix_table[x][i];
        if (temp > 1)
            ans += temp;
    }
    return ans;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    IOS;
    ll t = 1;
    // t = ll_scan();
    while (t--)
    {
        ll x = 1, k = 10;
        ll n = ll_scan();
        list<bool> ans;
        if (n == 0)
            cout << 0;
        else
            while (n != 0)
            {
                bool bit = n % 2;
                ans.push_front(bit);
                n = ceil(n / -2.0);
                x *= -2;
            }
        for (auto &it : ans)
            cout << it;
        // newline;
    }
}