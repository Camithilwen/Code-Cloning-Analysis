#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int x, y;
    cin >> x >> y;
    int ans = 0;
    if (x == 1)
    {
        ans += 300000;
    }
    else if (x == 2)
    {
        ans += 200000;
    }
    else if (x == 3)
    {
        ans += 100000;
    }
    if (y == 1)
    {
        ans += 300000;
    }
    else if (y == 2)
    {
        ans += 200000;
    }
    else if (y == 3)
    {
        ans += 100000;
    }
    if (ans == 600000)
    {
        ans += 400000;
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
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}