#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define txt                        \
    freopen("ip.txt", "r", stdin); \
    freopen("op.txt", "w", stdout)
#define a3 INT_MAX
#define i3 INT_MIN
#define a6 INT64_MAX
#define i6 INT64_MIN
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define fo(i, n) for (int i = 0; i < (int)n; i++)
#define rep(i, k, n) for (int i = k; k < (int)n ? i < (int)n : i > (int)n; k < (int)n ? i += 1 : i -= 1)
#define quickie                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define div2(a) (!(a & 1))
#define deb(x) cout << (#x) << " " << (x) << "\n";
#define newl cout << "\n"
#define all(s) s.begin(), s.end()
#define pi 3.14159265358979323846
#define fp(x) fixed << setprecision(x) <<
template <class T>
T mod(T a)
{
    if (a < 0)
    {
        a += 1000000007;
    }
    return a % 1000000007;
}
template <class T>
T addmod(T a, T b)
{
    return (mod(a) + mod(b)) % 1000000007;
}
template <class T>
T prodmod(T a, T b)
{
    return (mod(a) * mod(b)) % 1000000007;
}
template <class T>
T bin_exp(T a, T b)
{
    T res = 1;
    T temp = 1;
    if (b <= 1)
        return a;
    if (b % 2 == 0)
        res = bin_exp(a * a, b / 2);
    else
    {
        res *= a;
        temp = bin_exp(a, --b);
    }
    return res * temp;
}
template <class T>
T bin_expmod(T a, T b)
{
    T res = 1;
    T temp = 1;
    if (b <= 1)
        return a;
    if (b % 2 == 0)
        res = bin_expmod(prodmod(a, a), b / 2);
    else
    {
        res = prodmod(a, res);
        temp = bin_exp(a, --b);
    }
    return prodmod(res, temp);
}

template <class T>
int digit(T a)
{
    vector<long long> dig = {
        0,
        9,
        99,
        999,
        9999,
        99999,
        999999,
        9999999,
        99999999,
        999999999,
        9999999999,
        99999999999,
        999999999999,
        9999999999999,
        99999999999999,
        999999999999999,
        9999999999999999,
        99999999999999999,
        999999999999999999,
        INT64_MAX};
    auto it = lower_bound(dig.begin(), dig.end(), a);
    int idx = (it - dig.begin());
    return idx;
}
template <class T>
int sumAllInts(T n)
{
    int a = 1;
    int su = 0;
    while (n)
    {
        su += n % 10;
        n /= 10;
    }
    return su;
}
template <class T>
void split(char c, T s)
{
    int n = s.size();
    int i = 0;
    while ((cout << s[i], i += 1) && (i < n) && (cout << c << ' '))
        ;
}
void print(vi &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

void solve()
{
    int n,t;
    cin>>n>>t;
    int temp;cin>>temp;
    ll ans = t;
    fo(i,n-1){
        int te; cin>>te;
        int diff = te - temp;
        ans+=min(diff,t);
        temp = te;
    }
    cout<<ans;
}
int main()
{
    quickie;
    //txt;
    int t = 1;
    while (t--)
    {
        solve();
        newl;
    }
    return 0;
}