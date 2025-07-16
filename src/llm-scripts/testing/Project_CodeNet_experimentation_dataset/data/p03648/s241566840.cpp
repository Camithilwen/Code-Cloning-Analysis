#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
const int N = 50;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin >> k;
    cout << N << endl;
    for(int i = 0; i < N; i++) {
        if(i < N - 1 - (k - 1) % N) {
            cout << (k - 1) / N + i << " ";
        } else if(i == N - 1) {
            cout << (k - 1) / N + N << " ";
        } else {
            cout << (k - 1) / N + N - 1 << " ";
        }
    }
    cout << endl;
    return 0;
}
