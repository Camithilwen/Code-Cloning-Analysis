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

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void solve() {
    ll N;
    cin >> N;

    cout << 0 << endl;

    string r0;
    cin >> r0;

    if (r0 == "Vacant") {
        return;
    }

    string r;
    int left = -1, right = N;
    while (right - left > 1) {
        int mid = (left + right) >> 1;
        cout << mid << endl;
        cin >> r;
        if (r == "Vacant") {
            return;
        }

        if (mid & 1) {
            if (r == r0) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        else {
            if (r == r0) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
    }

    int cur = left + 1;
    while (true) {
        cout << cur << endl;
        cin >> r;
        if (r == "Vacant") break;
        ++cur;
    }
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
    solve();
    cout << flush;
    return 0;
}