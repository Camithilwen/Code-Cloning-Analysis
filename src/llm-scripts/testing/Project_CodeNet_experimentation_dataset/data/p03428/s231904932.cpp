#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-9;
const double PI = acos(-1.0);
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)

namespace std {
    bool operator<(const Point a, const Point b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

double dot(Point a, Point b) {
    return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b) {
    return a.X*b.Y - a.Y*b.X;
}

int ccw(Point a, Point b, Point c) {
    b -= a;  c -= a;
    if (cross(b,c) >  EPS) return +1;  // counter clockwise
    if (cross(b,c) < -EPS) return -1;  // clockwise
    if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
    if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
    return 0;                          // a--c--b on line or a==c or b==c
}

VP convexHull(VP ps) {  // 元の点集合がソートされていいならVP&に
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  VP ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;  // 余計な点も含むなら == -1 とする
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}

int main(void){
    VP vp;
    int n;
    cin>>n;
    rep(i,n){
        double x,y;
        cin>>x>>y;
        vp.push_back(Point(x,y));
    }

    VP ch = convexHull(vp);
    int m = ch.size();
    vector<double> range;
    rep(i,m){
        range.push_back(arg(ch[(i+1)%m]-ch[i]) - arg(ch[i]-ch[(m+i-1)%m]));
    }

    rep(i,n){
        bool inConvex = true;
        rep(j,m){
            if(vp[i] == ch[j]){
                inConvex = false;
                printf("%.10f\n", acos(cos(range[j]))/(2.0*PI));
                break;
            }
        }
        if(inConvex) printf("0.0\n");
    }

    return 0;
}
