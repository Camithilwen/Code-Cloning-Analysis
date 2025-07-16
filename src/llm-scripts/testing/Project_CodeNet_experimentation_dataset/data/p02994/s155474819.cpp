#include <bits/stdc++.h>
//#include <atcoder/all>
#define rep(i, n) for (int i=0; i < (n); i++)
using namespace std;
//using namespace atcoder;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int NIL = -1;
const int MAX = 10000;
const int MOD = 1000000007;
const double pi = 3.141592653589;

int main() {
    int n, l;
    cin >> n >> l;
    int taste = 0;
    int ate = INF;
    rep(i,n){
        taste += l + i;
        if(abs(ate) > abs(l+i)) ate = l+i;
    };
    cout << taste - ate << endl;
    return 0;
}