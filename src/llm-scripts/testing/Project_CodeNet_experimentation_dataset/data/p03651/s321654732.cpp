#include <iostream>

using namespace std;

long gcd(long a, long b){ return b? gcd(b,a%b) : a; }

int main() {
    int n,k;
    cin >> n >> k;
    long GCD;
    cin >> GCD;
    long _max = GCD;
    bool f = k == GCD;
    for (int i=1; i<n; i++) {
        long a;
        cin >> a;
        f = f || k==a;
        GCD = gcd(GCD, a);
        _max = max(_max, a);
    }


    if (f || (k%GCD==0 && k <= _max)) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

}
