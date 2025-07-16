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
    void solve() {
        Int N, M;
        cin >> N >> M;
        vector<Int> A(M);
        int ki = 0;
        for (int i = 0; i < M; ++i) {
            cin >> A[i];
            if (A[i] % 2) ki++;
        }

        if (ki > 2) {
            cout << "Impossible" << endl;
            return;
        }

        sort(all(A), [](Int a, Int b) {
            return a % 2 > b % 2;
        });


        if (A.size() > 1 && A[1] % 2 == 1) {
            swap(A[1], A.back());
        }
        vector<Int> B = A;
        if (B.size() == 1) {
            B.push_back(1);
            B[0]--;
            if (B[0] == 0) {
                swap(B[0], B[1]);
            }
        }

        B[0]--;
        B.back()++;
        if (B[0] == 0) {
            B.erase(B.begin());
        }
        if (B.back() == 0) {
            B.pop_back();
        }

        for (int i = 0; i < M; ++i) {
            cout << A[i] << " ";
        }
        cout << endl;
        cout << B.size() << endl;
        for (auto e : B) {
            cout << e << " ";
        }
        cout << endl;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
