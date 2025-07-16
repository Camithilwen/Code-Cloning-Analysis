/*
verified on 2019/12/13
vec2d<double> -> https://atcoder.jp/contests/agc021/submissions/8932641
vec2d<long>   -> https://atcoder.jp/contests/abc022/submissions/8932886
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/* ここからスニペット */
#include <complex>
#include <numeric>
#include <iomanip>


namespace geometry2d {
    using value_t = double;
    using point_t = complex<double>;

    // 内積, 外積
    inline value_t dot(point_t a, point_t b)   { return a.real() * b.real() + a.imag() * b.imag(); }
    inline value_t cross(point_t a, point_t b) { return a.real() * b.imag() - a.imag() * b.real(); }

    // 単位ベクトル, なす角のcos
    inline point_t unit(point_t p) { return p / abs(p); }
    inline value_t cos_between(point_t a, point_t b) { return dot(unit(a), unit(b)); }

    // 辞書順演算子
    inline bool operator<(const point_t l, const point_t r) {
        return (l.real() != r.real() ? l.real() < r.real() : l.imag() < r.imag());
    }
    inline bool operator>(const point_t l, const point_t r) {
        return (l.real() != r.real() ? l.real() > r.real() : l.imag() > r.imag());
    }
    inline bool operator<=(const point_t l, const point_t r) { return !(l > r); }
    inline bool operator>=(const point_t l, const point_t r) { return !(l < r); }



    // 点集合pointsに対して凸包を作る
    // ansに凸包の各点(pointsでのインデックス)が入る
    // 戻り値はansのサイズ
    int convex_hull(vector<point_t> &points, vector<int> &ans) {
        int n = (int)points.size();
        size_t k = 0;
        vector<size_t> lid((size_t)n), _ans((size_t)n * 2);

        // pointsを辞書順ソートしたときのインデックスの順列を作る
        iota(lid.begin(), lid.end(), 0);
        sort(lid.begin(), lid.end(), [&points](size_t l, size_t r) {
            return points[l] < points[r];
        });

        // 下側
        for (int i=0; i<n; i++) {
            while (k > 1 && cross(points[_ans[k-1]] - points[_ans[k-2]], points[lid[(size_t)i]] - points[_ans[k-1]]) <= 0)
                k--;
            _ans[k] = lid[(size_t)i];
            k++;
        }

        // 上側
        for (int i=n-2, s=(int)k; i>=0; i--) {
            while ((int)k > s && cross(points[_ans[k-1]] - points[_ans[k-2]], points[lid[(size_t)i]] - points[_ans[k-1]]) <= 0)
                k--;
            _ans[k] = lid[(size_t)i];
            k++;
        }

        for (size_t i=0; i<k-1; i++) ans.push_back((int)_ans[i]);

        return (int)k-1;
    }
} // namespace geometry2d

namespace std {
    istream &operator>>(istream &is, geometry2d::point_t &p) {
        geometry2d::value_t a, b;
        is >> a >> b;
        p = geometry2d::point_t(a, b);
        return is;
    }
    ostream &operator<<(ostream &os, geometry2d::point_t &p) {
        return os << fixed << setprecision(10) << p.real() << ' ' << p.imag();
    }
}


int main(){
    int n;
    cin >> n;
    vector<geometry2d::point_t> points(n);
    for (auto &pi:points) cin >> pi;
    vector<int> ch;
    int m = geometry2d::convex_hull(points, ch);
    double ans[n];
    fill(ans, ans+n, 0);
    geometry2d::point_t prev = points[ch[m-1]];
    for (int i=0; i<m; i++) {
        geometry2d::point_t cur  = points[ch[i]];
        geometry2d::point_t next = points[ch[(i+1)%m]];
        ans[ch[i]] = acos(geometry2d::cos_between(cur - prev, next - cur)) / (2 * M_PI);
        prev = cur;
    }
    for (auto &ai:ans) cout << fixed << setprecision(15) << ai << '\n';
    return 0;
}