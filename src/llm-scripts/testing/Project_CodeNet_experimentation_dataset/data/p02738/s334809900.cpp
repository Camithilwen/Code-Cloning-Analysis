# include<bits/stdc++.h>
# include<ext/pb_ds/assoc_container.hpp>
# include<ext/pb_ds/tree_policy.hpp>
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC optimize ("Ofast")

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

# define int long long
typedef long long ll;
typedef pair<int, int> pii;

# define S second
# define F first
# define kill(x) return(cout << x << '\n', 0LL)
# define debug(x) cerr<< #x << " = " << (x) << endl
# define ddebug(x, y) cerr<< #x << " = " << (x)  << ", " << #y << " = " << (y) << endl
# define tdebug(x, y, z) cerr<< #x << " = " << (x)  << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
# define bin(x) cerr<< #x << " : " << bitset<4>(x) << endl
# define sz(s) (int)s.size()
# define sq(x) (x) * (x)
# define PB(x) push_back(x)
# define smax(x, y) (x) = max((x), (y))
# define smin(x, y) (x) = min((x), (y))
# define all(x) x.begin(), x.end()
# define SP fixed << setprecision(10)
# define uop(x, y) pii(min(x, y), max(x, y))

const int MAXN = 2000 + 10;
int MOD,
    fact[3 * MAXN],
    inv[3 * MAXN],
    r2[3 * MAXN],
    r3[3 * MAXN];

int _pow(int a, int p)
{
    if (!p)
        return 1;
    return _pow(sq(a) % MOD, p >> 1) * (p & 1 ? a : 1) % MOD;
}

int rev(int a)
{
    return _pow(a, MOD - 2);
}

int ch(int n, int k)
{
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n >> MOD;

    fact[0] = 1;
    for (int i = 1; i <= n * 3 + 10; i ++)
        fact[i] = fact[i - 1] * i % MOD;

    for (int i = 0; i <= n * 3 + 10; i ++)
    {
        r2[i] = rev(_pow(2, i));
        r3[i] = rev(_pow(3, i));
        inv[i] = rev(fact[i]);
    }

    int ans = 0;
    for (int i = 0; i <= n; i ++)
        for (int j = i; i + (j - i) / 3 <= n; j += 3)
        {
            int k = n - i - (j - i) / 3;

            int x = ch(3 * n, j)
                    * ch(3 * n - j, 2 * i) % MOD
                    * fact[2 * i] % MOD
                    * r2[i] % MOD
                    * inv[i] % MOD
                    * fact[3 * k] % MOD
                    * r3[k] % MOD
                    * inv[k] % MOD;
            ans = (ans + x) % MOD;
        }
    cout << ans << endl;

	return 0;
}
