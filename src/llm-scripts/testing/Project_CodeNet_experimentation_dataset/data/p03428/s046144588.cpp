#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
using ld = long double;

const ld PI = acos(-1);

struct point {
    ld x, y;
};

int main() {
    int N;
    cin >> N;
    vector<point> coo(N);
    for (auto& p : coo) cin >> p.x >> p.y;

    for (int i = 0; i < N; ++i) {
        vector<ld> degs;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            degs.push_back(atan2(coo[i].y - coo[j].y, coo[i].x - coo[j].x));
        }
        sort(degs.begin(), degs.end());
        degs.push_back(degs.front() + PI * 2);

        ld ans = 0;
        for (int j = 0; j < N; ++j) {
            ans = max(ans, degs[j + 1] - degs[j] - PI);
        }
        cout << fixed << setprecision(10) << ans / (PI * 2) << endl;
    }

    return 0;
}
