#include<functional>
#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

template <typename T>
class BIT {
    // 1-indexed
    private:
        size_t node_size_;
        T identity_;
        function<T(T, T)> operation_;
        function<T(T, T)> update_;
        vector<T> node_;
    public:
        BIT(size_t node_size, T identity, function<T(T, T)> operation, function<T(T, T)> update):
            node_size_(node_size), identity_(identity), operation_(operation), update_(update), node_(vector<T>(node_size + 1, identity)) {}
        void change(int idx, T new_value) {
            node_[idx] = update_(node_[idx], new_value);
            while (idx <= (int)node_size_) {
                idx += idx & -idx;
                if (idx > (int)node_size_) {
                    break;
                }
                node_[idx] = operation_(node_[idx], new_value);
            }
        }
        T query(int idx) {
            T res = identity_;
            while (idx > 0) {
                res = operation_(res, node_[idx]);
                idx -= idx & -idx;
            }
            return res;
        }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    BIT<ll> bit(N, 0, [](ll a, ll b) {return a + b;}, [](ll a, ll b) {return a + b;});
    ll a;
    rep(i, 0, N) {
        cin >> a;
        bit.change(i + 1, a);
    }
    int q, p, l, r;
    ll x;
    rep(i, 0, Q) {
        cin >> q;
        if (q) {
            cin >> l >> r;
            cout << bit.query(r) - bit.query(l) << endl;
        } else {
            cin >> p >> x;
            bit.change(p + 1, x);
        }
    }
    return 0;
}