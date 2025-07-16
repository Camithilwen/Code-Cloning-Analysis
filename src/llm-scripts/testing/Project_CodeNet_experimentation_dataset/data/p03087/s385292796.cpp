//
//AtCoder Beginner Contest 122
//C
//https://atcoder.jp/contests/abc122/tasks/abc122_c
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
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<pair<int,int>> lr(n);
    REP(i, q) {
        cin >> lr[i].first >> lr[i].second;
        lr[i].first--;
        lr[i].second--;
    }
    vector<int> sAC(n+1, 0);
    int acCnt=0;
    REP(i,n){
        if ((s[i]=='A') && (s[i+1]=='C')) acCnt++;
        sAC[i+1]=acCnt;
    }
    REP(i,q){
        int ans = sAC[lr[i].second] - sAC[lr[i].first];
        cout << ans << endl;
    }
    return 0;
}
