#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
const double PI = acos(-1);
int n;
pair<int, int> p[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    for (int i = 1; i <= n; i++) {
        vector<double> V;
        for (int j = 1; j <= n; j++) if (i ^ j) {
            V.push_back(atan2(p[j].second - p[i].second, p[j].first - p[i].first));
        }
        sort(V.begin(), V.end());
        double ans = max(0.0, PI - (V.back() - V[0]));
        for (int i = 0; i + 1 < V.size(); i++) {
            ans = max(ans, (V[i + 1] - V[i]) - PI);
        }
        printf("%.10f\n", ans / PI / 2);
    }
    return 0;
}