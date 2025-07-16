#pragma GCC optimize("Ofast,fast-math,unroll-loops")
 
#include <bits/stdc++.h>
 
#define int ll
//#define double long double
#define endl '\n'
#define all(C) (C).begin(), (C).end()
#define rall(C) (C).rbegin(), (C).rend()
#define mp make_pair 
#define pb emplace_back
#define dbg(x) cerr << #x << " : " << x << endl
//#define PI 3.141592653589
 
using namespace std;
        
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair <int, int>;
using pld = pair <ld, ld>;
        
/* 
const ll MAX_MEM = 25e7;
char MEM[MAX_MEM];
ll MEM_POS = 0;
void* operator new(size_t x)
{
    auto ret = MEM + MEM_POS;
    MEM_POS += x;
    assert(MEM_POS < MAX_MEM);
    return ret;
}
void operator delete(void*)
{}
*/
        
template <class T>
istream& operator>> (istream &in, vector <T> &a)
{
    for (auto &i : a)
        in >> i;
    return in;
}
        
template <class T> 
ostream& operator<< (ostream &out, vector <T> a)
{
    for (auto &i : a)
        out << i << ' ';
    return out;
}
        
template <class T, class U>
istream& operator>> (istream &in, pair <T, U> &p)
{
    in >> p.first >> p.second;
    return in;
}
        
template <class T, class U>
ostream& operator<< (ostream &out, pair <T, U> p)
{
    out << p.first << " " << p.second << " ";
    return out;
}
        
inline void Start()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen("lol.in", "r", stdin);
    //freopen("lol.out", "w", stdout);
}

const int P = 1e9 + 7;
int add(int a, int b)
{
    return a + b >= P ? a + b - P : a + b;
}
int mul(int a, int b)
{
    return a * b % P;
}
int bpow(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
            res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
int rev(int x)
{
    return bpow(x, P - 2);
}
int sub(int a, int b)
{
    return add(a, P - b);
}
int divi(int a, int b)
{
    return mul(a, rev(b));
}
struct combinations
{
    vector <int> fact, revfact;
    combinations() {}
    combinations(int n)
    {
        fact.assign(n, 1);
        revfact.assign(n, 1);
        for (int i = 1; i < n; ++i)
            fact[i] = mul(fact[i - 1], i), revfact[i] = divi(revfact[i - 1], i);
    }
    int operator() (int n, int k)
    {
        return mul(fact[n], mul(revfact[k], revfact[n - k]));
    }
};

signed main()
{
    Start();
    int n, k;
    cin >> n >> k;
    combinations c(2001 * 2001);
    if (k == 1)
        return cout << 1, 0;
    vector <vector <int>> dp(n + 1, vector <int> (n + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = (i ? 0 : 1); j <= n; ++j)
        {
            if (j < i)
                continue;
            if (i)
                dp[i][j] = add(dp[i][j], dp[i - 1][j]);
            if (j)
                dp[i][j] = add(dp[i][j], mul(dp[i][j - 1], c(i + j * (k - 1) - 1, k - 2)));

        }
    }
    cout << mul(dp[n][n], c.fact[n]);
    return 0;
}
 
