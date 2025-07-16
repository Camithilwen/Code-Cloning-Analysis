#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll N; cin >> N;
    ll res = to_string(N).size();
    ll A,B;
    // A <= B としてA,Bを求める． A <= B より Bの桁数の方が大きいことに注意．
    for (ll A=1; A<=sqrt(N); A++){
        if (N%A != 0) continue;
        B = N/A;
        // res = min(ll(to_string(B).size()),res);
        res = min((ll)log10(B)+1, res);
    }
    cout << res << endl;
    return 0;
}