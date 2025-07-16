#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define all(v) (v).begin(),(v).end()
using ll = long long;
constexpr ll INF = 1e18;

vector<ll> solver(ll N, ll Q, vector<ll> a, vector<ll> t, vector<ll> u, vector<ll> v) {
    fenwick_tree<ll> fw(N);
    vector<ll> ans;
    for (int i = 0; i < N; i++) {
        fw.add(i, a[i]);
    }
    for (int i = 0; i < Q; i++) {
        if (t[i] == 0) {
            fw.add(u[i], v[i]);
        } else {
            ans.push_back(fw.sum(u[i], v[i]));
        }
    }
    return ans;
}

int main(void) {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    vector<ll> t(Q), u(Q), v(Q);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> t[i] >> u[i] >> v[i];
    }
    for (auto&& x : solver(N, Q, a, t, u, v)) {
        cout << x << endl;
    }
    return 0;
}
