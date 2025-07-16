#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

using std::setprecision;
using std::fixed;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

ll min(ll a, ll b) {return a < b ? a : b;}
ll min(int a, ll b) {return a < b ? a : b;}
ll min(ll a, int b) {return a < b ? a : b;}
ll min(int a, int b) {return a < b ? a : b;}

ll max(ll a, ll b) {return a > b ? a : b;}
ll max(int a, ll b) {return a > b ? a : b;}
ll max(ll a, int b) {return a > b ? a : b;}
ll max(int a, int b) {return a > b ? a : b;}

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
ll n, m, k;

vector<int> mul(vector<int> a, vector<int> b)
{
    vector<int> c(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        c[i] = a[b[i]];
    }
    return c;
}

vector<double> mul(vector<double> a, vector<int> b)
{
    vector<double> c(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        c[i] = a[b[i]];
    }
    return c;
}

vector<int> inq(vector<int> perm, ll k)
{
    if (k == 0)
    {
        vector<int> c;
        for (int i = 0; i < perm.size(); i++) c.push_back(i);
        return c;
    }
    vector<int> l = inq(perm, k / 2);
    if (k % 2) return mul(mul(l, l), perm);
    return mul(l, l);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<double> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    cin >> m >> k;
    vector<int> perm(n - 1);
    iota(all(perm), 0);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        x--;
        swap(perm[x - 1], perm[x]);
    }
    vector<int> c = inq(perm, k);
    vector<int> y(n - 1);
    for (int i = 0; i + 1 < n; i++)
    {
        y[i] = x[i + 1] - x[i];
    }
    y = mul(y, c);
    double s = x[0];
    for (int i = 0; i < n; i++)
    {
        printf("%.9f\n", s);
        if (i != n - 1)
            s += y[i];
    }
}
