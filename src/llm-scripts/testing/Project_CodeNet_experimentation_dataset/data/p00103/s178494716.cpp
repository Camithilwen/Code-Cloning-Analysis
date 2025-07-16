#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <numeric>
#include <sstream>
#include <queue>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define FOR(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define PUSH(n,v) for(int i=0; i<(n); i++) {int j; cin >> j; v.push_back(j);}
#define ALL(v) v.begin(), v.end()
#define print(s) cout << (s) << endl

int main() {
    int n;
    cin >> n;
    int a = 0, out = 0;
    int base[4] = {0};
    string s;
    while (cin >> s) {
        if (s == "HIT") {
            for (int i = 2; i >= 0; i--) {
                if (base[i]) base[i+1] = 1, base[i] = 0;
            }
            base[0] = 1;
            if (base[3]) {
                a++;
                base[3] = 0;
            }
        }else if (s == "HOMERUN") {
            REP(i,3) a += base[i];
            a++;
            REP(i,3) base[i] = 0;
        }else {
            out++;
        }
        if (out == 3) {
            cout << a << endl;
            out = 0;
            a = 0;
            REP(i,4) base[i] = 0;
        }
    }
}