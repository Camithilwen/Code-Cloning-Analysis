#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vec = vector<ll>;
using vect = vector<double>;
using Graph = vector<vector<ll>>;
#define loop(i, n) for (ll i = 0; i < n; i++)
#define Loop(i, m, n) for (ll i = m; i < n; i++)
#define pool(i, n) for (ll i = n; i >= 0; i--)
#define Pool(i, m, n) for (ll i = n; i >= m; i--)
#define mod 1000000007ll
//#define mod 998244353ll
#define flagcount __builtin_popcount
#define flag(x) (1 << x)
#define flagadd(bit, x) bit |= flag(x)
#define flagpop(bit, x) bit &= ~flag(x)
#define flagon(bit, i) bit &flag(i)
#define flagoff(bit, i) !(bit & (1 << i))
#define all(v) v.begin(), v.end()
#define low2way(v, x) lower_bound(all(v), x)
#define high2way(v, x) upper_bound(all(v), x)
#define idx_lower(v, x) (distance(v.begin(), low2way(v, x)))  //配列vでx未満の要素数を返す
#define idx_upper(v, x) (distance(v.begin(), high2way(v, x))) //配列vでx以下の要素数を返す
#define idx_lower2(v, x) (v.size() - idx_lower(v, x))         //配列vでx以上の要素数を返す
#define idx_upper2(v, x) (v.size() - idx_upper(v, x))         //配列vでxより大きい要素の数を返す
#define putout(a) cout << a << endl
#define Gput(a, b) G[a].push_back(b)
#define Sum(v) accumulate(all(v), 0ll)
#define gcd(x, y) __gcd(x, y)
ll ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return 0;
}
template <typename T>
T lcm(T x, T y)
{
    T z = gcd(x, y);
    return x * y / z;
}
template <typename T>
bool primejudge(T n)
{
    if (n < 2)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    double sqrtn = sqrt(n);
    for (T i = 3; i < sqrtn + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}
//場合によって使い分ける
//const ll dx[4]={1,0,-1,0};
//const ll dy[4]={0,1,0,-1};
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//2次元配列の宣言
//vector<vector<ll>> field(h, vector<ll>(w));

int main()
{
    cout << fixed << setprecision(30);
    ll D, G;
    cin >> D >> G;
    vec p(D), c(D);
    loop(i, D) cin >> p[i] >> c[i];
    ll ans = 1e9;
    loop(bit, 1 << D)
    {
        ll ac = 0;
        ll score = 0;
        bool check = false;
        loop(i, D) if (flagon(bit, i))
        {
            ac += p[i];
            score += p[i] * (i + 1) * 100;
            score += c[i];
            if (score >= G)
            {
                check = true;
                break;
            }
        }
        if (check)
        {
            ans = min(ans, ac);
            continue;
        }
        //もしも基準点に達していなければ、いままで選択していないなかでもっとも配点の高いシリーズから解いていく
        //もしも基準を満たせなかったら諦める
        bool check2 = false;
        for (ll i = D - 1; i >= 0; i--)
        {
            if (flagoff(bit, i))
            {
                loop(j, p[i])
                {
                    score += 100 * (i + 1);
                    ac++;
                    if (j == p[i] - 1)
                        score += c[i];
                    if (score >= G)
                    {
                        check2 = true;
                        break;
                    }
                }
                break;
            }
        }
        if (check2)
            ans = min(ans, ac);
    }
    putout(ans);
    return 0;
}
