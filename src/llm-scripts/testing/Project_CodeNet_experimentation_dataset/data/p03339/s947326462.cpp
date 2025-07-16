#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <utility> 
#include <tuple> 
#include <cstdint> 
#include <cstdio> 
#include <map> 
#include <queue> 
#include <set> 
#include <stack> 
#include <deque> 
#include <unordered_map> 
#include <unordered_set> 
#include <bitset> 
#include <cctype> 
#include <cmath>
#include <iomanip>
#include <ctype.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi >;
using vl = vector<ll>;
using vvl = vector<vl >;
using pairi = pair<int, int>;
using pairl = pair<ll, ll>;

#define TR ","
#define TS " "
#define rep(i,N) for(ll i=0;i<(ll)N;++i)
#define rpt(i,a,b) for(ll i=a;i<(ll)b;++i)
#define all(v) v.begin(), v.end()
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

void printVector(const vector<ll>& vec) {
    for (ll value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

vector<int> IntegerToVector(int bit, int N) {
    vector<int> S;
    for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) {
            S.push_back(i);
        }
    }
    return S;
}

int main()
{
    IO;

    ll N; cin >> N;
    string str; cin >> str;
    vl wkosuu(N), ekosuu(N);

    ll x = 0, y = 0, z=0;

    rep(i, N) {
        if (str[i] == 'E') { ++y; }
        else if (str[i] == 'W') { ++z; }
    }

    wkosuu[0] = 0;
    wkosuu[N - 1] = z;
    ekosuu[0] = y;
    ekosuu[N - 1] = 0;

    for (ll i = 1; i < N-1; ++i) {
        if (str[i-1] == 'E') {
            wkosuu[i] = wkosuu[i - 1];
        }
        else if (str[i-1] == 'W') {
            ++x;
            wkosuu[i] = x;
        }
    }

    for (ll i = 0; i < N-1; ++i) {
        if (str[i] == 'W') {
            if (i > 0) {
                ekosuu[i] = ekosuu[i - 1];
            }
        }
        else if (str[i] == 'E') {
            --y;
            ekosuu[i] = y;
        }
    }

    ll ans = N;

    rep(i, N) {
        ans = min(ans, wkosuu[i] + ekosuu[i]);
    }

    cout << ans << endl;

}