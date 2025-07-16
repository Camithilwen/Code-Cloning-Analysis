#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

class Match {

    multiset<ll> l, r;


public:
    void add(P p) {
        this->l.insert(p.first);
        this->r.insert(p.second);
    }

    ll point() {
        auto itl = l.end();
        itl--;
        ll lr = *itl;
        auto itr = r.begin();
        ll rl = *itr;

        return max<ll>(rl - lr + 1, 0);
    }

    void pop(P p) {
        l.erase(l.find(p.first));
        r.erase(r.find(p.second));
    }


};

int main() {
    int n;
    cin >> n;
    vector<P> v(n);
    for (P &p:v)cin >> p.first >> p.second;

    ll ans_one = [&] {
        Match a, b;
        rep(i, n) {
            b.add(v[i]);
        }

        ll ans = 0;
        rep(i, n) {
            b.pop(v[i]);
            a.add(v[i]);

            ll now = b.point() + a.point();
            cmax(ans, now);

            a.pop(v[i]);
            b.add(v[i]);
        }
        return ans;
    }();

    ll ans_split = [&]() -> ll {

        sort(v.begin(), v.end(), [](P p1, P p2) {
            return p1.second < p2.second;
        });

        Match a, b;
        for (P p : v) b.add(p);
        ll ans = 0;
        rep(i, n - 1) {
            P p = v[i];
            a.add(p);
            b.pop(p);
            ll now = a.point() + b.point();
            cmax(ans, now);
        }
        return ans;
    }();

    ll ans = max(ans_split, ans_one);

    cout << ans << endl;

}
