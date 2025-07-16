#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#define MOD(x) (x + 1000000007) % (1000000007)

using namespace std;

template <class t>
using vec = vector<t>;
using ll = long long;

const int MAX = numeric_limits<int>::max();

template <class t>
ostream &operator<<(ostream &out, vec<t> &v)
{
    for (auto &e : v)
        out << e << " ";
    out << "\n";
    return out;
}

template <class t>
istream &operator>>(istream &in, vec<t> &v)
{
    for (auto &e : v)
        in >> e;
    return in;
}

int n;
vec<vec<ll>> a;
vec<ll> dp, pre;

void find(ll used, vec<int> &not_used, ll group_mask, int index)
{
    if (index == not_used.size())
    {
        dp[used | group_mask] = max(dp[used | group_mask], dp[used] + pre[group_mask]);
        return; 
    }
    find(used, not_used, group_mask, index + 1);
    find(used, not_used, group_mask | (1 << not_used[index]), index + 1);
}

int main()
{
    cin >> n;
    a = vec<vec<ll>>(n, vec<ll>(n));
    cin >> a;
    dp = vec<ll>(1 << n);
    pre = vec<ll>(1 << n);
    for (ll mask = 0; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                for (int j = i + 1; j < n; j++)
                    if (mask & (1 << j))
                        pre[mask] += a[i][j];
    for (ll mask = 0; mask < (1 << n); mask++)
    {
        vec<int> not_used;
        for (int i = 0; i < n; i++)
            if (!(mask & (1 << i))) not_used.push_back(i);
        find(mask, not_used, 0, 0);
    }
    cout << dp[(1 << n) - 1];
    return 0;
}