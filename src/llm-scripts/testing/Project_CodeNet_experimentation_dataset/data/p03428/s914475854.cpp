#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;
typedef vector<Point> Polygon;
typedef pair<Point, double> Circle;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

namespace std{
    bool operator<(const Point &a, const Point &b){
        return !equals(a.X, b.X) ? a.X < b.X : a.Y < b.Y;
    }

    bool cmp_y(const Point &a, const Point &b) {
        return !equals(a.Y, b.Y) ? a.Y < b.Y : a.X < b.X;
    }
}

double dot(Vector a, Vector b){
    return a.X * b.X + a.Y * b.Y;
}

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
}

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if(cross(a, b) < -EPS) return CLOCKWISE;
    if(dot(a, b) < -EPS) return ONLINE_BACK;
    if(norm(a) < norm(b)) return ONLINE_FRONT;

    return ON_SEGMENT;
}

Polygon convexHull(Polygon ps){
    int n = ps.size();
    sort(ps.begin(), ps.end(), cmp_y);
    int k = 0;
    Polygon convex(n * 2);
    for(int i=0; i<n; i++){
        while(k >= 2 && ccw(convex[k-2], convex[k-1], ps[i]) == CLOCKWISE) k--;
        convex[k++] = ps[i];
    }
    for(int i=n-2, t=k; i>=0; i--){
        while(k > t && ccw(convex[k-2], convex[k-1], ps[i]) == CLOCKWISE) k--;
        convex[k++] = ps[i];
    }
    convex.resize(k-1);
    return convex;
}

double arg(Vector p){
    return atan2(p.Y, p.X);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    Polygon pol;
    vector<double> x(n), y(n);
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
        pol.emplace_back(x[i], y[i]);
    }

    pol = convexHull(pol);

    int m = pol.size();

    map<pair<double, double>, double> ans;
    for(int i=0; i<m; i++){
        Vector A = pol[(i+1)%m] - pol[i];
        Vector B = pol[(i-1+m)%m] - pol[i];
        Vector C = pol[(i+1)%m] - pol[(i-1+m)%m];

        double cos_i = (abs(A) * abs(A) + abs(B) * abs(B) - abs(C) * abs(C)) / (2 * abs(A) * abs(B));
        double theta = acos(cos_i);
        theta = pi - theta;
        double alpha = theta / 2 / pi;
        ans[make_pair(pol[i].X, pol[i].Y)] = alpha;
    }

    for(int i=0; i<n; i++){
        printf("%.8f\n", ans[make_pair(x[i], y[i])]);
    }
}