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
#define int long long

const int N = 333333;
const int MOD = 998244353;

char sumb = '#';

int n, m;
string s[5000];

int d[2100][2100];

bool bd(int i, int j)
{
    int cnt = 0;
    cnt += s[i - 1][j] == sumb;
    cnt += s[i - 1][j + 1] == sumb;
    cnt += s[i][j] == sumb;
    cnt += s[i][j + 1] == sumb;
    return cnt % 2;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int j = 0; j < m - 1; j++)
        d[n][j] = n;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m - 1; j++)
        {
            d[i][j] = d[i + 1][j];
            if (i && bd(i, j)) d[i][j] = i;
        }
    }
    int ans = max(n, m);
    for (int i = 0; i < n; i++)
    {
        vector<int> r(m);
        vector<int> l(m);
        for (int j = 0; j < m; j++) r[j] = j, l[j] = j;
        vector<vector<pair<int, int> > > v(n + 2);
        for (int j = 0; j + 1 < m; j++)
        {
            int x = d[i + 1][j];
            v[x].push_back({j, j + 1});
        }
        int s = 1;
        for (int j = n; j > i; j--)
        {
            for (int k = 0; k < v[j].size(); k++)
            {
                int R = v[j][k].first;
                int L = v[j][k].second;
                int RR = r[L];
                int LL = l[R];
                int len = RR - LL + 1;
                s = max(s, len);
                l[RR] = LL;
                r[LL] = RR;
            }
            //cout << i << " " << j << " " << s * (j - i) << "\n";
            ans = max(ans, s * (j - i));
        }
    }
    cout << ans;
}
