#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    // 約数までしか作れない
    int n, k;
    cin >> n >> k;
    set<int> nums;
    int gcd;
    rep(i, n)
    {
        int a;
        cin >> a;
        nums.insert(a);
        if (i == 0)
        {
            gcd = a;
            continue;
        }
        if (a == k)
        {
            cout << "POSSIBLE" << endl;
            return 0;
        }
        gcd = __gcd(n, a);
    }
    if (gcd == 1 || k % gcd == 0)
    {
        if (*rbegin(nums) >= k)
        {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
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
