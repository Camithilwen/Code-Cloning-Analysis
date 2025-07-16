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
#define endl '\n'
#define debug(x) std::cerr << #x << " = " << (x) << endl;

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

template<typename T>
class BinaryIndexedTree2D {
    int H;
    int W;
    std::vector<std::vector<T> > data2d;
public:
    BinaryIndexedTree2D(int H, int W) : H(H), W(W) {
        data2d.resize(H + 1, std::vector<T>(W + 1, 0));
    }

    T sum(int h, int w) {
        T res = 0;
        for (int i = h; i > 0; i -= i & -i) {
            for (int j = w; j > 0; j -= j & -j) {
                res += data2d[i][j];
            }
        }
        return res;
    }

    /**
     * 左上の座標(h1, w1), 右下の座標(h2, w2) に含まれる値の累積和
     */
    T sum(int h1, int w1, int h2, int w2) {
        return sum(h2, w2) - sum(h1 - 1, w2) - sum(h2, w1 - 1) + sum(h1 - 1, w1 - 1);
    }

    void add(int h, int w, ll x) {
        for (int i = h; i <= H; i += i & -i) {
            for (int j = w; j <= W; j += j & -j) {
                data2d[i][j] += x;
            }
        }
    }
};

ll N;
BinaryIndexedTree2D<ll> bit( 100, 100 );
constexpr ll base = 20;

int main() {
  std::cin >> N;

  ll ans = 0;

  rep( i, N ) {
    std::string A;
    std::cin >> A;

    bool fst = true;
    ll p = A.size();
    ll ten = 1;
    ll s = 0, num = 0;

    if( A.find('.') != std::string::npos ) repd( i, A.size() ) {
      if( A[i] != '0' ) {
        if( fst ) {
          p = i;
        }

        fst = false;
      }

      if( !fst && A[i] != '.' ) {
        num += (A[i]-'0')*ten;
        ten *= 10;
      }

      if( A[i] == '.' ) {
        s = p-i;
      }
    } else {
      rep( i, A.size() ) {
        num *= 10;
        num += A[i]-'0';
      }

      s = 0;
    }

    //std::cout << P(num, s) << endl;

    ll two = 0, five = 0;

    while( num % 2 == 0 ) {
      num /= 2;
      ++two;
    }

    while( num % 5 == 0 ) {
      num /= 5;
      ++five;
    }

    //std::cout << P(two-s, five-s) << endl;

    ans += bit.sum( -(two-s)+base, -(five-s)+base, 98, 98 );
    //std::cout << "sum: " << P(-(two-s)+base, -(five-s)+base) << endl;

    bit.add( two-s+base, five-s+base, 1 );
    //std::cout << "added: " << P(two-s+base, five-s+base) << endl;
  }

  std::cout << ans << endl;

  return 0;
}