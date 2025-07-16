//
//AtCoder Beginner Contest 125
//D
//https://atcoder.jp/contests/abc125/tasks/abc125_d
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <functional>
#include <cassert>
#include <bitset>
#include <numeric>

using namespace std;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SIZE(x) (int)(x).size()
#define SIZEL(x) (ll)(x).size()
#define MSG(a) cout << #a << " " << a << endl;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

const double PI = 3.14159265358979323846;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }            //最小公倍数

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    
    int mCnt=0;
    int mMax=1e9*-1;
    int pMin=1e9;
    REP(i, n) {
        cin >> a[i];
        if (a[i]<0) {
            mCnt++;
            mMax = max(mMax, a[i]);
        }else{
            pMin = min(pMin, a[i]);
        }

    }

    ll ans=0;
    REP(i,n) ans+=abs(a[i]);
    if (mCnt%2==1){
        ans -= 2*min(pMin, abs(mMax));
    }
    cout << ans << endl;
    return 0;
}
