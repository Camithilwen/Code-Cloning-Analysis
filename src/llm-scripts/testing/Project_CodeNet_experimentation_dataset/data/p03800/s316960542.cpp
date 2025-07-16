#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

char next_char(char now, char pre, string &s, int k) {
    if (s[k]=='o') {
        if (now=='S') return pre;
        else if (pre=='W') return 'S';
        else return 'W';
    }
    else {
        if (now=='W') return pre;
        else if (pre=='W') return 'S';
        else return 'W';
    }
}

int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    
    map<int,string> mp;
    mp[0] = "S";
    mp[1] = "W";

    rep(i,2) rep(j,2) {
        string ans = mp[i] + mp[j];
        rep(k,N-1) {
            char now = ans[k+1];
            char pre = ans[k];
            char next = next_char(now,pre,s,k+1);
            if (k==N-2) {
                if (next==ans[0]) {
                    pre = now;
                    now = ans[0];
                    next = next_char(now,pre,s,0);
                    if (next==ans[1]) {
                        cout << ans << endl;

                        return 0;
                    }
                }
            }
            else {
                ans += next;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
