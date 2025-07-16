#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> x(10), y(10);

double dist (int i, int j) {
    double dx = x.at(i) - x.at(j);
    double dy = y.at(i) - y.at(j);
    return pow(dx*dx + dy*dy, 0.5);
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> x.at(i) >> y.at(i);
    double sum = 0.0;
    vector<int> v(n);
    rep(i,n) v.at(i) = i + 1;
    
    do {
        for (int i = 0; i < n - 1; ++i) sum += dist(v.at(i), v.at(i+1));
    } while (next_permutation(v.begin(), v.end()));

    int factorial = 1;
    for (int i = 1; i <= n; ++i) factorial *= i;
    cout << std::fixed << std::setprecision(15);
    cout << sum / factorial << endl;

    return 0;
}