#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;

using Real = double;
using Point = complex< Real >;
const Real EPS = 1e-8, PI = acos(-1);
using Polygon = vector< Point >;

namespace std {
  bool operator<(const Point &a, const Point &b) {
    return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
  }
}

inline bool eq(Real a, Real b) { return fabs(b - a) < EPS; }
Real cross(const Point &a, const Point &b) {
  return real(a) * imag(b) - imag(a) * real(b);
}

Real dot(const Point &a, const Point &b) {
  return real(a) * real(b) + imag(a) * imag(b);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
// 点の回転方向
int ccw(const Point &a, Point b, Point c) {
  b = b - a, c = c - a;
  if(cross(b, c) > EPS) return +1;  // "COUNTER_CLOCKWISE"
  if(cross(b, c) < -EPS) return -1; // "CLOCKWISE"
  if(dot(b, c) < 0) return +2;      // "ONLINE_BACK"
  if(norm(b) < norm(c)) return -2;  // "ONLINE_FRONT"
  return 0;                         // "ON_SEGMENT"
}

Point operator*(const Point &p, const Real &d) {
  return Point(real(p) * d, imag(p) * d);
}

istream &operator>>(istream &is, Point &p) {
  Real a, b;
  is >> a >> b;
  p = Point(a, b);
  return is;
}

ostream &operator<<(ostream &os, Point &p) {
  os << fixed << setprecision(10) << p.real() << " " << p.imag();
}

Polygon convex_hull(Polygon &p) {
  int n = (int) p.size(), k = 0;
  if(n <= 2) return p;
  sort(p.begin(), p.end());
  vector< Point > ch(2 * n);
  for(int i = 0; i < n; ch[k++] = p[i++]) {
    while(k >= 2 && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS) --k;
  }
  for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
    while(k >= t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS) --k;
  }
  ch.resize(k - 1);
  return ch;
}

int main(){
    int n;
    cin >> n;
    Polygon v(n);
    map<Point,int> ma;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ma[v[i]] = i;
    }
    auto p = convex_hull(v);
    vector<double> ans(n,0.0);
    if(p.size()==2){
        for (int i = 0; i < p.size(); i++) {
            ans[ma[p[i]]] = 1./2;
        }
    }
    else{
        for (int i = 0; i < p.size(); i++) {
            Point a = p[(i+1)%p.size()] - p[i];
            Point b = p[(i-1+p.size())%p.size()] - p[i];
            double theta = acos(dot(a,b) / abs(a) / abs(b));
            ans[ma[p[i]]] = (PI - theta) / 2 / PI;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << setprecision(30) << ans[i] << endl;
    }
    return 0;
}
