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
#define PI 3.1415926535
 
using namespace std;
        
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair <int, int>;
using pld = pair <ld, ld>;

/*
const ll MAX_MEM = 3e6;
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

vector <int> bpow(vector <int> a, int n, int k)
{
    vector <int> p(n);
    iota(all(p), 0);
    for (int i = 0; i < a.size(); ++i)
        swap(p[a[i]], p[a[i] - 1]);
    vector <int> res(n);
    iota(all(res), 0);
    while (k)
    {
        if (k & 1)
        {
            vector <int> r = res;
            for (int i = 0; i < n; ++i)
                res[i] = r[p[i]];
        }
        vector <int> r = p;
        for (int i = 0; i < n; ++i)
            p[i] = r[r[i]];
        k >>= 1;
    }
    return res;
}

signed main()
{
    Start();
    int n;
    cin >> n;
    vector <int> x(n);
    cin >> x;
    vector <int> d(n - 1);
    for (int i = 1; i < n; ++i)
        d[i - 1] = x[i] - x[i - 1];
    int m, k;
    cin >> m >> k;
    vector <int> a(m);
    cin >> a;
    for (auto &i : a)
        --i;
    a = bpow(a, n - 1, k);
    auto t = d;
    for (int i = 0; i < n - 1; ++i)
        d[i] = t[a[i]];
    d.pb(0);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cout << x[0] + sum << endl;
        sum += d[i];
    }
    return 0;
}


