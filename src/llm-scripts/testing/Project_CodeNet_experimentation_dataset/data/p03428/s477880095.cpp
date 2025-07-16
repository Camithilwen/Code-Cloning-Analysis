#include<iostream>
// Need start
#include<vector>
#include<algorithm>
#include<functional>
// Need end
#include<cmath>
#include<iomanip>
using namespace std;

// Copy start
template<typename T>
class Polygon2D {
    private:
        T x_, y_;
        int idx_;
    public:
        Polygon2D() {}
        Polygon2D(T x, T y):x_(x), y_(y) {}
        Polygon2D(T x, T y, int idx):x_(x), y_(y), idx_(idx) {}  // for convex-full
        static T dot(const Polygon2D<T>& p1, const Polygon2D<T>& p2) {return p1.x_ * p2.x_ + p1.y_ * p2.y_;}
        static T det(const Polygon2D<T>& p1, const Polygon2D<T>& p2) {return p1.x_ * p2.y_ - p1.y_ * p2.x_;}
        static T pow(const Polygon2D<T>& p) {return dot(p, p);}
        const Polygon2D operator=(const Polygon2D<T>& p) {x_ = p.x_; y_ = p.y_; idx_ = p.idx_; return *this;}
        const Polygon2D operator+(const Polygon2D<T>& p) const {Polygon2D<T> res = *this; res.x_ += p.x_; res.y_ += p.y_; return res;}
        const Polygon2D operator-(const Polygon2D<T>& p) const {Polygon2D<T> res = *this; res.x_ -= p.x_; res.y_ -= p.y_; return res;}
        T getX() const {return x_;}
        T getY() const {return y_;}
        int getIdx() const {return idx_;}
        friend ostream& operator<<(ostream& stream, const Polygon2D& p) {stream << '(' << p.x_ << ',' << p.y_ << ')'; return stream;}
};

// Graham's scan
template<typename T>
vector<Polygon2D<T> > convex_hull(vector<Polygon2D<T> > ps, int vertex_num) {
    sort(ps.begin(), ps.end(), [](const Polygon2D<T>& p, const Polygon2D<T>& q) {
        if (p.getX() != q.getX()) return p.getX() < q.getX();
        return p.getY() < q.getY();
    });
    int k = 0;
    vector<Polygon2D<T> > qs(vertex_num * 2);
    // bottom
    for (int i = 0; i < vertex_num; i++) {
        while (k > 1 && Polygon2D<T>::det(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    // up
    for (int i = vertex_num - 2, t = k; i >= 0; i--) {
        while (k > t && Polygon2D<T>::det(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k - 1);
    return qs;
}
// Copy end

const double PI = 3.14159265358979323846264338327950288;

int main() {
    // This sample is AtCoder Grand Contest 21 B
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<Polygon2D<double>> ps(N);
    double x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        ps[i] = Polygon2D<double>(x, y, i);
    }
    if (N == 2) {
        cout << fixed << setprecision(7);
        cout << 0.5 << endl;
        cout << 0.5 << endl;
        return 0;
    }
    vector<Polygon2D<double> > qs = convex_hull(ps, N);
    qs.push_back(qs[0]);
    qs.push_back(qs[1]);
    vector<double> ans(N, 0.0);
    for (int i = 0; i < (int)qs.size() - 2; i++) {
        Polygon2D<double> pr = qs[i] - qs[i + 1], pq = qs[i + 2] - qs[i + 1];
        double len_pr = Polygon2D<double>::pow(pr);
        double len_pq = Polygon2D<double>::pow(pq);
        ans[qs[i + 1].getIdx()] = (PI - acos(Polygon2D<double>::dot(pr, pq) / sqrt(len_pr * len_pq))) / (2 * PI);
    }
    cout << fixed << setprecision(7);
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}