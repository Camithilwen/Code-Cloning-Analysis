#include <bits/stdc++.h>
#define REP(i,n) for (int i=0; i<(n); ++i)
#define REPR(i,n,m) for (int i=(n); i>=(m); --i)
using namespace std;
using LL = long long;
using LD = long double;
using PLL = pair<long long, long long>;
using PLD = pair<long double, long double>;
using VLL = vector<long long>;
using VLD = vector<long double>;
using VPLL = vector<PLL>;
using VPLD = vector<PLD>;

const int INF = numeric_limits<int>::max();

// (x, y) の最大公約数を返す関数
LL GCD(LL x, LL y) {
    return y ? GCD(y, x%y) : x;
}

VPLL prime_factorize(LL n) {
    VPLL res;
    for (LL p=2; p*p<=n; p++) {
        if (n%p!=0) continue;
        int num = 0;
        while (n%p==0) {num++; n/=p;}
        res.push_back(make_pair(p,num));
    }
    if (n!=1) res.push_back(make_pair(n,1));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    LL a, b;
    cin >> a >> b;
    long long G = GCD(a,b);
    auto pf = prime_factorize(G);

    cout << pf.size()+1 << endl;    

    return 0;
}
