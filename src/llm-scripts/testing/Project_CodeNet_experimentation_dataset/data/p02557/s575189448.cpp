#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        --A[i];
    }
    vector<int> B(n);
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
        --B[i];
    }

    const int INF = 1 << 24;
    vector<pair<int,int>> rangesA(n, make_pair(INF, -INF));
    vector<pair<int,int>> rangesB(n, make_pair(INF, -INF));

    for (int i = 0; i < n; ++i) {
        int l = i;
        int x = A[i];
        while (i + 1 < n && A[i + 1] == x) {
            ++i;
        }
        int r = i;
        rangesA[x] = make_pair(l, r);
    }
    for (int i = 0; i < n; ++i) {
        int l = i;
        int x = B[i];
        while (i + 1 < n && B[i + 1] == x) {
            ++i;
        }
        int r = i;
        rangesB[x] = make_pair(l, r);
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        int cntA = rangesA[i].second - rangesA[i].first + 1;
        int cntB = rangesB[i].second - rangesB[i].first + 1;
        if (cntA > 0 && cntB > 0 && cntA > n - cntB) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "No\n";
        return 0;
    }


    vector<int> cnts(2 * n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int la = rangesA[i].first, ra = rangesA[i].second;
        int lb = rangesB[i].first, rb = rangesB[i].second;
        if (la >= n || lb >= n) {
            continue;
        }

        int r = ra - lb;
        if (r < 0) {
            r += n;
        }
        int l = (la - (rb - lb)) - lb;
        while (l < 0) {
            l += n;
        }
        while (l > r) {
            r += n;
        }
        // cout << i << " : " << l << " - " << r << endl;
        cnts[l] += 1;
        cnts[r + 1] -= 1;
    }
    for (int i = 1; i < cnts.size(); ++i) {
        cnts[i] += cnts[i - 1];
    }

    int offset = -1;
    for (int i = 0; i < n; ++i) {
        if (cnts[i] + cnts[i + n]== 0) {
            offset = i;
            break;
        }
    }

    vector<int> res(n, 0);
    for (int i = 0; i < n; ++i) {
        res[i] = (B[(i - offset + n) % n]);
    }


    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << res[i] + 1 << (i == n - 1 ? '\n' : ' '); 
    }
    return 0;
}