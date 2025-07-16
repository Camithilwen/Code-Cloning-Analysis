#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdio>
#include <iomanip>
#include <utility>
#include <unordered_map>

using namespace std;
typedef long long int ll;

#define SP(x) setprecision((int)x)
#define SW(x) setw(x)    // 桁数指定
#define SF(c) setfill(c) // 埋め文字指定('0')
#define ALL(v) v.begin(), v.end()

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    vector<ll> a(n);

    ll cnt = 0;

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
            cnt++;
    }

    for (ll i = 0; i < n; i++)
    {
        if (a[i] < 0)
            a[i] *= -1;
    }
    
    if (cnt % 2 == 1)
    {
        sort(ALL(a));
        a[0] *= -1;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += a[i];
    }
    cout << ans << endl;
}