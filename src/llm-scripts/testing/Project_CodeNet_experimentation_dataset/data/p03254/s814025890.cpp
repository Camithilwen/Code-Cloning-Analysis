#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N, x;
    cin >> N >> x;
    vector<ll> a(N);
    rep(0, i, N)
    {
        cin >> a.at(i);
    }
    sort(all(a));
    ll ans = 0;
    rep(0, i, N)
    {
        x -= a.at(i);
        if (x < 0)
        {
            break;
        }
        ans++;
    }
    if (x > 0)
    {
        ans--;
    }
    cout << ans << endl;
}