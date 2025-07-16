#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    ll X;
    cin >> X;
    ll tmp = X / 11;
    if(X - 11 * tmp == 0) cout << 2 * tmp << endl;
    else if (X - 11 * tmp <= 6) cout << 2 * tmp + 1 << endl;
    else cout << 2 * tmp + 2 << endl;
}