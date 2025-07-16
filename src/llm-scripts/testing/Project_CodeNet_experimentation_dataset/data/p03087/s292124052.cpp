#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> ac(n);
    vector<int> sum(n + 1, 0);
    rep(i, n) {
        if(i != n) {
            if(s[i] == 'A' && s[i + 1] == 'C') {
                ac[i]++;
                i++;
            }
        }
    }
    rep(i, n) {
        sum[i + 1] += sum[i] + ac[i];
    }
    /*cout << endl;
    rep(i, n) cout << ac[i] << ' ';
    cout << endl;
    rep(i, n + 1) cout << sum[i] << ' ';
    cout << endl;
    //確認済*/
    vector<vector<int>> l(q, vector<int>(2));
    rep(i, q) {
        rep(j, 2) cin >> l[i][j];
    }
    rep(i, q) {
        cout << sum[l[i][1] - 1] - sum[l[i][0] - 1] << endl;
    }

}