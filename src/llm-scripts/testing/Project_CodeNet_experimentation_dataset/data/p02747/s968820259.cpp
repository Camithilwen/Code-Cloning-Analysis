#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define pi 3.14159265358979323
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    string s;
    cin >> s;
    if (s.size() % 2 != 0) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, s.size()) {
        if (i % 2 == 0 && s.at(i) != 'h') {
            cout << "No" << endl;
            return 0;
        }
        else if (i % 2 == 1 && s.at(i) != 'i') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}