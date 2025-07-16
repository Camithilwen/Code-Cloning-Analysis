#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repdi(i,a,b) for(ll i=(a)-1;i>=(b);--i)
#define repd(i,a) repdi(i,a,0)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

using ll = long long;
using P = std::pair<ll, ll>;

constexpr ll INF = 1ll<<60;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class S, class T>
std::ostream& operator<< ( std::ostream& out, const std::pair<S,T>& a )
{ std::cout << '(' << a.first << ", " << a.second << ')'; return out; }

template<class T>
std::ostream &operator<< ( std::ostream& out, const std::vector<T>& a )
{ std::cout << '['; rep( i, a.size() ){ std::cout << a[i]; if( i != a.size()-1 ) std::cout << ", "; } std::cout << ']'; return out; }

ll A, B, M;
ll a[100010], b[100010];
ll mi = INF;
std::vector<P> cost[100010];

int main()
{
  std::cin >> A >> B >> M;

  rep( i, A )
    std::cin >> a[i];

  rep( i, B )
    std::cin >> b[i], chmin( mi, b[i] );

  rep( i, M ) {
    ll x, y, c;
    std::cin >> x >> y >> c;
    --x; --y;
    cost[x].emplace_back( y, c );
  }

  ll ans = INF;

  rep( i, A ) {
    chmin( ans, a[i]+mi );

    for( auto p : cost[i] )
     chmin( ans, a[i]+b[p.first]-p.second );
  }

  std::cout << ans << std::endl;

  return 0;
}