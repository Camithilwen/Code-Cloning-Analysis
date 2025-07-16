#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using VVI = vector<vector<int>>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    vector<ll> mid(n + 1);
    for (int i = 0; i < n; i++)
    {
        int idx = distance(a.begin(), lower_bound(a.begin(), a.end(), b[i]));
        mid[i + 1] = mid[i] + idx;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = distance(b.begin(), lower_bound(b.begin(), b.end(), c[i]));
        ans += mid[idx];
    }
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}