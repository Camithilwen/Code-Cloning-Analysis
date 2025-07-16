#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int len;
    cin >> len;
    string s, t;
    cin >> s >> t;
    int slen = s.size(), tlen = t.size();
    for (; len > 0; len--) {
        int si = slen - len;
        int ti = 0;
        if (s.substr(si, len) == t.substr(ti, len)) {
            break;
        }
    }

    cout << s.size() * 2 - len << '\n';
}