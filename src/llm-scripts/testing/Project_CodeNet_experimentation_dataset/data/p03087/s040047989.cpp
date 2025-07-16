#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,Q; cin >> N >> Q;
    string S; cin >> S;

    vector<int> AC(N,0);
    FOR(i,1,N){
        if(S[i-1]=='A' && S[i]=='C'){
            AC[i] += 1;
        }
        AC[i] += AC[i-1];
    }


    REP(i,Q){
        int l,r; cin >> l >> r;
        l--;
        r--;
        cout << AC[r] - AC[l] << endl;
    }
    return 0;
}