#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <math.h> // sqrt
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <iomanip> // setprecision
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<long long>;
using pii = pair<int, int>;
using psi = pair<string, int>;

int N;

int f(vector<vector<pair<int, int>>> &data, vi &bit, int n) {
    if (n == 0) {
        int ans = 0;
        bool check = false;
        for (int i = 0; i < N; i++) {
            if (bit[i] == 0) {
                continue;
            }
            ans++;
            for (pair<int, int> p : data[i]) {
                if (bit[p.first - 1] != p.second) {
                    return 0;
                }
            }
        }
        return ans;
    }
    bit[N - n] = 1;
    int a = f(data, bit, n - 1);
    bit[N - n] = 0;
    int b = f(data, bit, n - 1);
    return max(a, b);
}

int main() {
    cin >> N;
    vi a(N);
    vector<vector<pair<int, int>>> data(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        vector<pair<int, int>> v(a[i]);
        for (int j = 0; j < a[i]; j++) {
            int x, y;
            cin >> x >> y;
            v[j] = {x, y};
        }
        data[i] = v;
    }
    vi bit(N, 0);
    int ans = f(data, bit, N);
    cout << ans << endl;
}
