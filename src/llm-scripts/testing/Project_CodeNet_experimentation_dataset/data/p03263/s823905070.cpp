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
using PP = std::pair<P, P>;

constexpr ll INF = 1ll<<60;

constexpr ll dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class S, class T>
std::ostream& operator<< ( std::ostream& out, const std::pair<S,T>& a )
{ std::cout << '(' << a.first << ", " << a.second << ')'; return out; }

template<class T>
std::ostream &operator<< ( std::ostream& out, const std::vector<T>& a )
{ std::cout << '['; rep( i, a.size() ){ std::cout << a[i]; if( i != a.size()-1 ) std::cout << ", "; } std::cout << ']'; return out; }

ll H, W;
std::vector<P> ps;
ll a[510][510];
bool used[510][510];
std::vector<PP> ans;

int main()
{
  std::cin >> H >> W;

  std::vector<P> ps;

  rep( i, H ) rep( j, W )
    std::cin >> a[i][j];

  ll dir = 1;
  ll ci = 0, cj = 0;

  while( true ) {
    ll ni, nj;
    
    if( (dir==1 && cj == W-1) || (dir==-1 && !cj) ) {
      dir *= -1;
      ni = ci+1, nj = cj;
    } else {
      ni = ci, nj = cj+dir;
    }

    if( used[ni][nj] || ci >= H )
      break;

    if( (a[ci][cj]&1) && ni < H ) {
      --a[ci][cj];
      ++a[ni][nj];

      ans.emplace_back( P( ci+1, cj+1 ), P( ni+1, nj+1 ) );
    }

    ci = ni;
    cj = nj;
  }

  std::cout << ans.size() << std::endl;

  for( auto pp : ans )
    printf( "%lld %lld %lld %lld\n", pp.first.first, pp.first.second, pp.second.first, pp.second.second );

  return 0;
}