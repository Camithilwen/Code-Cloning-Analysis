#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
vector<int> factor(int x) {
    vector<int> ret;
    int y = x;
    for (int i = 1; i * i <= y; i++) {
        if (y % i == 0) {
            ret.push_back(i);
            if (i * i != y) ret.push_back(y / i);
        }
    }
    return ret;
}
/* main */
int main(){
    int N;
    cin >> N;
    vector<int> a(N+1);
    for (int i = 1; i <= N; i++) cin >> a[i];

    vector<int> cnt(N+1, 0);
    vector<int> ball;
    for (int i = N; i >= 1; i--) {
        if ((cnt[i] % 2) == a[i]) continue;
        ball.push_back(i);
        vector<int> factors = factor(i);
        for (int f : factors) cnt[f]++;
    }

    reverse(ball.begin(), ball.end());
    int M = ball.size();
    cout << M << '\n';
    for (int i = 0; i < ball.size(); i++) {
        if (i) cout << ' ';
        cout << ball[i];
    }
    cout << '\n';
}