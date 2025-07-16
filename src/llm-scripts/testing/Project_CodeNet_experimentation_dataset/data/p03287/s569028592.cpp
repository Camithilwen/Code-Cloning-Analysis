#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <math.h>
#include <bitset>
#include <queue>
#include <set>
#include <iomanip>
#include <assert.h>
#include <cstdio>

// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr long long int infll = 1001001001001001LL;
constexpr int INF = 1000000007;
constexpr int inf = 1000000007;
const int mod = 1000000007;

inline bool chmin(ll &a, ll b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

inline bool chmax(ll &a, ll b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
T seinomi(T a)
{
    if (a > 0)
    {
        return a;
    }
    else
    {
        return 0;
    }
}

//桁数取得
template <typename T>
T ketasuu(T num)
{
    return std::to_string(num).length();
}
//整数乗
ll llpow(ll a, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        ll rep = a;
        for (ll i = 1; i < n; i++)
        {
            rep *= a;
        }
        return rep;
    }
}

template <class ForwardIt, class T>
void iota(ForwardIt first, ForwardIt last, T value)
{
    while (first != last)
    {
        *first++ = value;
        ++value;
    }
}

template <typename T>
T amarinasi(T a, T b)
{
    if (a % b == 0)
    {
        return a / b;
    }
    else if (a % b > 0)
    {
        return a / b + 1;
    }
    else
    {
        return a / b - 1;
    }
}

//小数点以下10桁テンプレート（main関数内の最初に貼付け）
//std::cout << std::fixed << std::setprecision(10);

//----------------------------------------------------------------
//組み合わせ nCr
vector<vector<ll>> nCr_v(5010, vector<ll>());
bool nCr_maekeisan = false;
void nCr_Calculater()
{
    for (int i = 0; i < 5010; i++)
    {
        nCr_v[i][0] = 1;
        nCr_v[i][i] = 1;
    }
    for (int k = 1; k < 5010; k++)
    {
        for (int j = 1; j < k; j++)
        {
            nCr_v[k][j] = (nCr_v[k - 1][j - 1] + nCr_v[k - 1][j]);
        }
    }
}
ll nCr(ll n, ll r)
{
    if (n > 5010 || r > 5010)
    {
        cout << "ERROR! over range" << endl;
        return 0;
    }
    if (n < 0 || r < 0)
    {
        return 0;
    }
    else
    {
        if (nCr_maekeisan == false)
        {
            for (ll i = 0; i < 5010; i++)
            {
                nCr_v[i].resize(5010);
            }
            nCr_Calculater();
            nCr_maekeisan = true;
        }
        return nCr_v[n][r];
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> rensou;
    ll ruiseki[n + 1];
    ruiseki[0] = a[0] % m;
    rensou[ruiseki[0]]++;
    for (ll i = 0; i < n; i++)
    {
        ruiseki[i + 1] = ruiseki[i] + a[i];
        ruiseki[i + 1] %= m;
        rensou[ruiseki[i + 1]]++;
    }
    ll ans = 0;
    for (auto f : rensou)
    {
        ans += ((f.second) * (f.second - 1)) / 2;
    }
    cout << ans << endl;
}
