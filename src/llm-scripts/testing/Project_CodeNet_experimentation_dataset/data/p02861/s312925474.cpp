#include <bits/stdc++.h>
using namespace std;
using pdd = pair<double, double>;

int main() {
    int N; cin >> N;
    vector<pdd> points(N);
    for (int i = 0; i < N; i++) {
        double x, y; cin >> x >> y;
        points[i] = make_pair(x, y);
    }
    vector<vector<double>> dist(N, vector<double>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
        }
    }
    vector<int> perm(N);
    for (int i = 0; i < N; i++) perm[i] = i;
    double ans = 0;
    double n_fact = 1.0;
    for (int i = 1; i <= N; i++) n_fact *= i;
    do {
        double pathlen = 0;
        for (int i = 0; i < N - 1; i++) pathlen += dist[perm[i]][perm[i+1]];
        ans += pathlen / n_fact;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << fixed << setprecision(10) << ans << endl;
}