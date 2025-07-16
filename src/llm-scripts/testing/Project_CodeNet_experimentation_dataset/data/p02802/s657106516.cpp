
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
#include <assert.h>
#include <deque>
#include <functional>
using namespace std;
typedef long long ll;

#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < n; i++)
#define debugA cerr << "AAAAA" << endl
#define debug_ cerr << "-------------" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    cout << #v << endl;                \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;
#define debug_vec2(v)                         \
    cout << #v << endl;                       \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
        {                                     \
            cout << v[i][j] << " ";           \
        }                                     \
        cout << endl;                         \
    }

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
void quit(T a)
{
    cout << a << endl;
    exit(0);
}

using Graph = vector<vector<int>>;
using P = pair<int, int>;
using P1 = pair<int, pair<int, int>>; // クラスカル法とかで、{cost, {from, to}}的に使う。
const ll LINF = 10010020030040056ll;
const int INF = 1001001001;
const double pi = acos(-1);

void MergeSort(vector<int> &a, int left, int right)
{
    if (right - left == 1)
        return;

    int mid = (right + left) / 2;
    MergeSort(a, left, mid);
    MergeSort(a, mid, right);
    int i = left;
    int j = mid;
    vector<int> tmp;
    while (true)
    {
        if (i == mid && j == right)
        {
            break;
        }
        else if (i == mid)
        {
            tmp.push_back(a.at(j));
            j++;
            continue;
        }
        else if (j == right)
        {
            tmp.push_back(a.at(i));
            i++;
            continue;
        }
        if (a[i] <= a[j])
        {
            tmp.push_back(a.at(i));
            i++;
        }
        else
        {
            tmp.push_back(a.at(j));
            j++;
        }
    }
    for (int i1 = left; i1 < right; i1++)
    {
        a.at(i1) = tmp.at(i1 - left);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        vec[i] = {0, 0};
    }
    for (int i = 0; i < m; i++)
    {
        int a;
        string s;
        cin >> a >> s;
        a--;
        if (s == "WA" && vec[a].fi == 0)
        {
            vec[a].se++;
        }
        else if (s == "WA")
        {
            continue;
        }
        else
        {
            vec[a].fi++;
        }
    }
    int ac = 0;
    int wa = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i].fi != 0)
        {
            ac++;
            wa += vec[i].se;
        }
    }
    cout << ac << " " << wa << endl;

    return 0;
}
