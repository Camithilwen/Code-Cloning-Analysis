#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define mp make_pair
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int di[] = {0, 0, 1, -1};
constexpr int dj[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll k;
    cin >> k;

    ll n = (k + 49) / 50;
    ll m = (50 - (k % 50)) % 50;

    cout << 50 << endl;

    ll a[50];

    REP(i, 50)
    a[i] = 49 + n;

    REP(i, m)
    {
        sort(a, a + 50);

        REP(j, 49)
        a[j]++;

        a[49] -= 50;
    }

    REP(i, 50)
    cout << a[i] << endl;

    return 0;
}