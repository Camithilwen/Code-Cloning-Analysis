#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n;
    cin >> n;
    vector<queue<int>> A(n);
    int a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            cin >> a;
            A[i].push(a-1);
        }
    }

    int res = 0;
    while (1) {
        bool fin = true;
        bool loop = true;
        vector<bool> checked(n, false);
        for (int i = 0; i < n; ++i) {
            if (checked[i]) continue;

            if (A[i].empty()) {
                continue;
            } else {
                fin = false;
            }

            if (A[A[i].front()].front() == i && !checked[A[i].front()]) {
                checked[i] = true;
                checked[A[i].front()] = true;

                A[A[i].front()].pop();
                A[i].pop();
                loop = false;
            }
        }
        if (fin) break;
        if (loop) {
            cout << -1 << endl;
            return 0;
        }
        res++;
    }
    cout << res << endl;
}