#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//改造
typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する
class Solve {
public:

    Int modmul(Int a, Int b) {
        return a * b % MOD;
    }

    void solve() {
        Int N;
        string S;

        cin >> N >> S;
        N *= 2;

        vector<int> LR(N);
        if (S[0] == 'W' || S.back() == 'W') {
            cout << 0 << endl;
            return;
        }

        LR[0] = 0;
        for (int i = 1; i < N; ++i) {
            if (S[i - 1] == S[i]) {
                LR[i] = 1 - LR[i - 1];
            } else {
                LR[i] = LR[i - 1];
            }
        }

        Int ans = 1;
        Int tapi = 0;
        for (int i = 0; i < N; ++i) {
            if (LR[i] == 0) {
                tapi++;
            } else {
                ans = modmul(ans, tapi);
                tapi--;
            }
        }
       
        if (tapi != 0) {
            cout << 0 << endl;
            return;
        }

        for (int i = 0; i < N / 2; ++i) {
            ans = modmul(ans, i + 1);
        }

        cout << ans << endl;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
