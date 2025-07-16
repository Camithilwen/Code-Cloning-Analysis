//----------------------------------------------------------------------
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n;
    cin >> n;
    vector<pair<double, double>> xy(n);
    rep(i, n) {
        cin >> xy[i].first >> xy[i].second;
    }
    vector<int> keiro;
    rep(i, n)
        keiro.push_back(i);

    double ans = 0.0;
    double sum = 0.0;
    do {
        for(int i = 0; i < n - 1; ++i) {
            double dx = xy[keiro[i+1]].first - xy[keiro[i]].first;
            double dy = xy[keiro[i+1]].second- xy[keiro[i]].second;
            ans += sqrt(dx * dx + dy * dy);
        }
        sum++;
    }while(next_permutation(keiro.begin(), keiro.end()));
    ans /= sum;

    cout << fixed << setprecision(16) <<
        ans << endl;
    return 0;
}
