#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9 + 7;
const int INF = 2e18;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    {
        bool check = (A[0] == 0);
        for (int i = 1; i < N - 1; i++) {
            if (A[i] > i) check = false;
        }
        if (!check) {
            cout << -1 << endl;
            return 0;
        }
    }
    int ans = 0;
    for (int i = N - 1; i >= 1;) {
        ans += A[i];
        int count = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] != A[i] - ++count) {
                if (A[j] < A[i] - count) {
                    cout << -1 << endl;
                    return 0;
                }
                i = j;
                break;
            }
            if (j == 0) i = 0;
        }
    }
    cout << ans << endl;
}
