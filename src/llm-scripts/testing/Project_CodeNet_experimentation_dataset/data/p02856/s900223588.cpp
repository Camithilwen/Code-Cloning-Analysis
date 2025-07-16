#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll s=0, t=0;
    for(int i=0; i<n; i++) {
        ll x,y;
        cin >> x >> y;
        s += x*y;
        t += y;
    }
    ll k=s%9;
    if(k==0) k=9;
    cout << t-1+(s-k)/9 << endl;
}