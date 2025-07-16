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

int main() {
    int N;
    string S;
    cin >> N >> S;
    ll r = 0, g = 0, b = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            r++;
        }
        else if (S[i] == 'G') {
            g++;
        }
        else {
            b++;
        }
    }
    ll ans = r * g * b;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 2; j < N; j += 2) {
            int k = (i + j) / 2;
            if (S[i] != S[j] && S[j] != S[k] && S[k] != S[i]) {
                ans--;
            }
        }
    }
    cout << ans << endl;
}