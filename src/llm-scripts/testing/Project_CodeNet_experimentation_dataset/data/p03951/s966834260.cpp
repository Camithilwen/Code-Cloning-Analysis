#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
        int N;
        string s, t;
        cin >> N >> s >> t;
        int ans = 2*N;
        rep(i,N) {
                if (s.substr(i,N-i) == t.substr(0,N-i) ){ ans = N+i; break;}
        }
        cout << ans << endl;

        return 0;
}