#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>    // bitset
#include <deque>     // deque
#include <iomanip>   //setprecsion
#include <iostream>  // cout, endl, cin
#include <map>       // map
#include <queue>     // queue, priority_queue
#include <set>       // set
#include <stack>     // stack
#include <string>    // string, to_string, stoi
#include <tuple>     // tuple, make_tuple
#include <utility>   // pair, make_pair
#include <vector>    // vector

#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>  //sin, cos, tan

using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

typedef vector<ll> vll;
typedef vector<ld> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvd;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<str>> vvs;
typedef vector<pair<ll, ll>> vpll;

const ld PI = acos(-1.0);
const ll MAX = 9000000000000000000;
const ll MIN = -9000000000000000000;
const ll MOD = 1000000007;

template <typename T>
void fin(T a)
{
    cout << a << endl;
    exit(0);
}

void Main()
{
    ll n; cin >> n;
    str ans;
    while(n)
    {
        n--;
        ans.pb((char)(n % 26 + 'a'));
        n /= 26;
    }
    reverse(all(ans));
    fin(ans);    
}

//前処理
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10); //高精度少数表示
    Main();
    return 0;
}
