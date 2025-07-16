#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
enum class event_t { start, end, query };
struct event {
    event_t type;
    int pos, val;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<event> events;
    for(int i = 0; i < n; i++) {
        int s, t, x;
        cin >> s >> t >> x;
        events.push_back({event_t::start, s - x, x});
        events.push_back({event_t::end, t - x, x});
    }
    for(int i = 0; i < q; i++) {
        int d;
        cin >> d;
        events.push_back({event_t::query, d, i});
    }
    vector<int> ans(q);
    sort(events.begin(), events.end(), [](auto& e1, auto& e2) {
        return pair{e1.pos, e1.type} < pair{e2.pos, e2.type};
    });
    multiset<int> s;
    for(auto& e : events) {
        if(e.type == event_t::start) {
            s.insert(e.val);
        } else if(e.type == event_t::end) {
            s.erase(s.find(e.val));
        } else {
            ans[e.val] = s.empty() ? -1 : *s.begin();
        }
    }
    for(int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
