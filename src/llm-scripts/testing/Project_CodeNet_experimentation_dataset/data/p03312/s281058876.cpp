#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

class Prints {
private:
    class __Prints {
    public:
        __Prints(const char* sep, const char* term) : sep(sep), term(term) {}
        template <class... Args>
        void operator()(Args&&... args) const { print(std::forward<Args>(args)...); }

    private:
        const char *sep, *term;
        void print() const { std::cout << term; }
        void print_rest() const { std::cout << term; }
        template <class T, class... Tail>
        void print(T&& head, Tail&&... tail) const { std::cout << head, print_rest(std::forward<Tail>(tail)...); }
        template <class T, class... Tail>
        void print_rest(T&& head, Tail&&... tail) const { std::cout << sep << head, print_rest(std::forward<Tail>(tail)...); }
    };

public:
    Prints() {}
    __Prints operator()(const char* sep = " ", const char* term = "\n") const { return __Prints(sep, term); }
    template <class T>
    void print_vec(const std::vector<T>& vec, const char* sep = " ", const char* term = "\n") const {
        const size_t sz = vec.size();
        for (size_t i = 0; i < sz; i++) std::cout << vec[i] << (i == sz - 1 ? term : sep);
    }
};

Prints prints;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void solve() {
    ll N;
    cin >> N;
    Vl A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    Vl cum(N + 1);
    for (ll i = 0; i < N; i++) {
        cum[i + 1] = cum[i] + A[i];
    }
    ll ans = L_INF;
    ll idx1 = 1, idx2 = 3;
    for (ll i = 2; i < N - 1; i++) {
        while (idx1 < i && cum[idx1] < cum[i] - cum[idx1]) {
            ++idx1;
        }
        while (idx2 < N - 1 && cum[idx2] - cum[i] < cum[N] - cum[idx2]) {
            ++idx2;
        }
        ll p1 = cum[idx1 - 1];
        ll p2 = cum[idx1];
        ll q1 = cum[i] - cum[idx1 - 1];
        ll q2 = cum[i] - cum[idx1];
        ll r1 = cum[idx2 - 1] - cum[i];
        ll r2 = cum[idx2] - cum[i];
        ll s1 = cum[N] - cum[idx2 - 1];
        ll s2 = cum[N] - cum[idx2];
        ll t = L_INF;
        t = min(t, max({p1, q1, r1, s1}) - min({p1, q1, r1, s1}));
        t = min(t, max({p2, q2, r1, s1}) - min({p2, q2, r1, s1}));
        t = min(t, max({p1, q1, r2, s2}) - min({p1, q1, r2, s2}));
        t = min(t, max({p2, q2, r2, s2}) - min({p2, q2, r2, s2}));
        ans = min(ans, t);
    }
    prints()(ans);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif
#ifdef FILEOUTPUT
    ofstream ofs("./in_out/output.txt");
    cout.rdbuf(ofs.rdbuf());
#endif
    cout << setprecision(18) << fixed;
    solve();
    cout << flush;
    return 0;
}