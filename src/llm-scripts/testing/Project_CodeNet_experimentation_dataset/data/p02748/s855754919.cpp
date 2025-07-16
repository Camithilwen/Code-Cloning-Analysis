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
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> veca(a);
    vector<int> vecb(b);
    int minia = INF;
    int minib = INF;
    rep(i, a) {
        cin >> veca.at(i);
        minia = min(minia, veca.at(i));
    }
    rep(i, b) {
        cin >> vecb.at(i);
        minib = min(minib, vecb.at(i));
    }
    int mini = minia + minib;
    int dismini = INF;
    vector<vector<int> > dis(m, vector<int> (3));
    rep(i, m) {
        rep(j, 3) {
            cin >> dis.at(i).at(j);
        }
        dismini = min(dismini, veca.at(dis.at(i).at(0) - 1) + vecb.at(dis.at(i).at(1) - 1) - dis.at(i).at(2));
    }
    cout << min(dismini, mini) << endl;
}