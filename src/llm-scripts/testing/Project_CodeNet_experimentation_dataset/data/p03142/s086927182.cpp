/*
    Author:zeke
    
    pass System Test!
    GET AC!!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <math.h>
#include <utility>
#include <stack>
#include <bitset>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll mod = 1e9 + 7;
unsigned long long MOD = 1e9 + 7;
ll INF = 1e18;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; // 頂点数
    cin >> n;
    ll m;
    cin >> m;
    m = n - 1 + m; // 辺数

    vector<pair<int, int>> edge(n); // first -> second
 //   cout << "hello" << endl;
    vector<vector<int>> eList(n); // 隣接リスト
    vector<int> inDeg(n, 0);   // 入次数
    rep(i,m)
    {
        ll A,B;
        cin >> A >> B;
        A--;
        B--;
        eList[A].push_back(B);
        inDeg[B]++;
    }
    queue<int> zeroQue; // 入次数 0 の頂点でまだ取られていないものを入れる
    for (int i = 0; i < n; i++)
    {
        if (inDeg[i] == 0){
            zeroQue.push(i);
        }
    }
 //   cout << "hello" << endl;
    V Result(n);
    vector<int> result; // トポロジカルソートの結果を入れる
    while (!zeroQue.empty())
    {
        int u = zeroQue.front(); // 入次数 0 の頂点 u を 1 つ取る
        zeroQue.pop();

        result.push_back(u);
        for (int v : eList[u])
        {               // u を始点とする辺すべてについて、
            inDeg[v]--; // 終点の入次数を減らす
            if (inDeg[v] == 0){
                zeroQue.push(v); // 入次数が 0 になったら取ることができる
                Result[v] = u+1;
             //   cout<<u<<endl;
            }
        }
    }
  //  cout << "hello" << endl;
    rep(i, n)
    {
        cout << Result[i] << endl;
    }
}
