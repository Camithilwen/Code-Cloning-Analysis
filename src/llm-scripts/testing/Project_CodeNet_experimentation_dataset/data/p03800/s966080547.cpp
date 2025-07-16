#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;

int N;
string s;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> s;
    rep(a, 2) rep(b, 2) {
        int A[N];
        A[0] = a;
        A[1] = b;
        for (int i=2; i<N; i++) {
            if (s[i-1]=='o' && A[i-1]==0) A[i] = A[i-2];
            else if (s[i-1]=='o' && A[i-1]==1) A[i] = 1^A[i-2];
            else if (s[i-1]=='x' && A[i-1]==0) A[i] = 1^A[i-2];
            else A[i] = A[i-2];
        }
        
        bool flag = true;
        if (s[0]=='o' && A[0]==0) flag &= A[1]==A[N-1];
        else if (s[0]=='o' && A[0]==1) flag &= A[1]!=A[N-1];
        else if (s[0]=='x' && A[0]==0) flag &= A[1]!=A[N-1];
        else if (s[0]=='x' && A[0]==1) flag &= A[1]==A[N-1];
        
        if (s[N-1]=='o' && A[N-1]==0) flag &= A[0]==A[N-2];
        else if (s[N-1]=='o' && A[N-1]==1) flag &= A[0]!=A[N-2];
        else if (s[N-1]=='x' && A[N-1]==0) flag &= A[0]!=A[N-2];
        else if (s[N-1]=='x' && A[N-1]==1) flag &= A[0]==A[N-2];
        
        if (flag) {
            rep(i, N) {
                if (A[i]==0) cout << 'S';
                else cout << 'W';
            }
            cout << endl;
            exit(0);
        }
    }
    cout << -1 << endl;
}