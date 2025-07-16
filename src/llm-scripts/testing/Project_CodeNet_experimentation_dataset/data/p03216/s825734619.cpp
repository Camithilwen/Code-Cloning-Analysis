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
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    vector<int> K(Q);
    for (int i = 0; i < Q; i++) cin >> K[i];

    vector<int> sum(N+1);
    for (int k : K) {
        ll D = 0, M = 0, ans = 0;
        ll cntDM = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == 'D') D++;
            else if (S[i] == 'M') {
                M++;
                cntDM += D;
            }
            else if (S[i] == 'C') {
                int l = max(i - k, 0), r = i + 1;
                ans += cntDM;
            }
            if (i >= k - 1) {
                if (S[i - (k - 1)] == 'D') {
                    D--;
                    cntDM -= M;
                }
                else if (S[i - (k - 1)] == 'M') M--;
            }
        }
        cout << ans << '\n';
    }
}
