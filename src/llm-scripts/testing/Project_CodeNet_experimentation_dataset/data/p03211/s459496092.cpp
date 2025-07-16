#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll S;
    ll N = 1;
    cin >> S;
    while (S/(ll)pow(10,N)) {
        //cout << pow(10,N) << endl;
        //cout << S/pow(10,N) << endl;
        //cout << N << endl;
        N++;
    }
    //cout << N << endl;
    ll ans = 1000;

    for(int i = 0; i < N-2; i++) {
        ans = min(ans,abs(753 - (S/(int)pow(10,i))%1000));
    }
    cout << ans << endl;




    return 0;
}