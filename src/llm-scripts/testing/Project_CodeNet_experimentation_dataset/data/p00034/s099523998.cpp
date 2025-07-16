#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
#define rrep(i, m, n) for(int (i)=(m); (i)<(n);  (i)++)
#define erep(i, m, n) for(int (i)=(m); (i)<=(n); (i)++)
#define  rep(i, n)    for(int (i)=0; (i)<(n);  (i)++)
#define rrev(i, m, n) for(int (i)=(n)-1; (i)>=(m); (i)--)
#define erev(i, m, n) for(int (i)=(n); (i)>=(m); (i)--)
#define  rev(i, n)    for(int (i)=(n)-1; (i)>=0; (i)--)
#define vrep(i, c)    for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); i++)
#define  ALL(v)       (v).begin(), (v).end()
#define mp            make_pair
#define pb            push_back
template<class T, class S> inline bool minup(T& m, S x){ return m>(T)x ? (m=(T)x, true) : false; }
template<class T, class S> inline bool maxup(T& m, S x){ return m<(T)x ? (m=(T)x, true) : false; }

const double INF = 1000000000;
const ll     MOD = 1000000007LL;
const double EPS = 1E-12;

template<typename T> T add(T x, T y){ if(abs(x+y) < EPS*(abs(x)+abs(y))) return 0; return x + y; }
template<typename T> inline bool semieq(T x, T y){ return abs(x - y) < EPS; }
template<typename T> inline bool semige(T x, T y){ return y - x < -EPS; }
template<typename T> inline bool semile(T x, T y){ return x - y < -EPS; }

const int MAX_N = 10;
const int n = MAX_N;
double x[MAX_N+1];
double v[2];

int main()
{
  while(~scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6], &x[7], &x[8], &x[9], &v[0], &v[1])){
    double len = 0.0;
    rep(i, n) len += x[i];
    double left  = 0.0;
    double right = INF;
    double t;
    while(semile(left, right)){
      t = (left + right) / 2.0;
      if((v[0] + v[1]) * t > len) right = t;
      else left = t;
    }
    rep(i, n-1) x[i+1] += x[i];
    cout << upper_bound(x, x+n, v[0] * t) - x + 1<< endl;
  }

  return 0;
}