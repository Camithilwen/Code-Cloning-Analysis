#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(ll i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll,ll> P;
typedef long double ld;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n <= 2) {
        cout << "-1\n";
    } else if (n % 3 == 0) {
        rep (i, n) {
            rep (j, n) {
                if (i / 3 == j / 3 && ((i % 3 == 0) ^ (j % 3 == 0))) cout << 'a';
                else cout << '.';
            }
            cout << "\n";
        }
    } else if (n == 7) {
        cout << "abb...a\n"
             << "a.a...a\n"
             << "bba...c\n"
             << "...abbc\n"
             << "...a.ab\n"
             << "...bbab\n"
             << "bbaacc.\n";
    } else if (n == 11) {
        cout << "bccaabbccaa\n"
             << "babb...abbc\n"
             << "ca.a...a.ac\n"
             << "cbba...bbab\n"
             << "baccbcc...b\n"
             << "ba.ab.b...a\n"
             << "accaccb...a\n"
             << "a...baacaab\n"
             << "b...b.bc.cb\n"
             << "b...aabaaca\n"
             << "ccaabbccbba\n";
    } else {
        int a, b;
        for (int i = n / 5; i >= 0; i--) {
            if ((n - 5 * i) % 4 == 0) {
                a = i;
                b = (n - 5 * i) / 4;
                break;
            } 
        }
        // eprintf("a=%d, b=%d\n", a, b);
        vector<string> s4 = {"aaca", "bbca", "acbb", "acaa"},
                       s5 = {"aacca", "c.bba", "cb..c", "ab..c", "accaa"};
        rep (i, n) {
            rep (j, n) {
                if (i / 5 == j / 5 && i / 5 < a) {
                    // cout << 1;
                    cout << s5[i % 5][j % 5];
                } else if ((i - 5 * a) / 4 == (j - 5 * a) / 4 && i - 5 * a >= 0 && j - 5 * a >= 0) {
                    // cout << 2;
                    cout << s4[(i - 5 * a) % 4][(j - 5 * a) % 4];
                } else {
                    // cout << 3;
                    cout << '.';
                }
            }
            cout << "\n";
        }
    }
    return 0;
}