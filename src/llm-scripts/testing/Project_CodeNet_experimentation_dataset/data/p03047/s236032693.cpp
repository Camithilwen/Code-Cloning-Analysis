#pragma region RegionDefs
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define reps(i,l,r) for(int i=(l),i##_len=(r);i<i##_len;++i)
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
const ll INF = 1e9;
template<class T=ll> using V = vector<T>;
template<class T=ll> using PQ = priority_queue<T>;
template<class T=ll> using PQG = priority_queue<T, V<T>, greater<T>>;
const ll MOD = 1000000007LL;
void in() {}
template<class Head, class... Tail>
void in(Head&& head, Tail&&... tail)
{
    cin >> head;
    in(move(tail)...);
}
#define IN(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define INS(T, ...) T __VA_ARGS__; in(__VA_ARGS__)
#define VIN(T, v, n) V<T> v(n); for(auto& _elem:v)cin>>_elem
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if (a>b) {a=b; return 1;} return 0;}
#define y0 y__0
#define y1 y__1
#define j0 j__0
#define j1 j__1
#define YN(e) cout << ((e) ? "YES" : "NO") << endl
#define yn(e) cout << ((e) ? "Yes" : "No") << endl
#pragma endregion RegionDefs

void solve()
{
    IN(n, k);
    cout << n - k + 1 << endl;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(numeric_limits<double>::max_digits10);

    solve();

    return 0;
}