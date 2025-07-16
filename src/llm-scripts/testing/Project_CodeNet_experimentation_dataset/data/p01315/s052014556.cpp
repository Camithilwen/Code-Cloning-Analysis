#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

template<class T> void vin(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

struct f {
    string l;
    int  p, a, b, c, d, e, f, s, m;
    double rate;
    void input() {
        cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
    }
    void calc() {
        double k = 0;
        rep(i, m) {
            if (i == 0) k += a+b+c+d+e;
            else k += d+e;
        }
        double kk = (f*m*s)-p;
        rate = kk/k;
    }
    void print() {
        cout << l << endl;
    }
};

int main() {
    int n;
    int count = 0;
    while (cin >> n) {
        if (n == 0) break;
        vector<f> a(n);
        rep(i, n) {
            a[i].input();
            a[i].calc();
        }
        sort(a.begin(), a.end(), [](const f& a, const f& b) {
            if (a.rate == b.rate) {
                return a.l < b.l;
            }
            return a.rate > b.rate;
        });
        rep(i, n) {
            a[i].print();
        }
        cout << "#" << endl;
    }
    return 0;
}

