#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<ll, ll> P;
int n;
string s;
vector<char> ans(100005);

void tyosa() {
    REPN(i, 1, n) {
        if(ans[i] == 'S') {
            if(s[i] == 'o') ans[(i+1)%n] = ans[i-1];
            else ans[(i+1)%n] = ans[i-1] == 'S' ? 'W' : 'S';
        } else {
            if(s[i] == 'x') ans[(i+1)%n] = ans[i-1];
            else ans[(i+1)%n] = ans[i-1] == 'S' ? 'W' : 'S';                
        }
    }
}

bool hantei() {
    if(s[0] == 'o') {
        if(ans[0] == 'S') {
            if(ans[n-1] == ans[1]) {
                return true;
            }
        } else {
            if(ans[n-1] != ans[1]) {
                return true;
            }            
        }
    } else {
        if(ans[0] == 'S') {
            if(ans[n-1] != ans[1]) {
                return true;
            }
        } else {
            if(ans[n-1] == ans[1]) {
                return true;
            }            
        }        
    }

    return false;
}

int main(){
    cin >> n >> s;
    char zenkai;

    /* 羊、羊 */
    ans[0] = 'S';
    zenkai = 'S';
    ans[1] = 'S';
    tyosa();
    if(zenkai == ans[0]) {
        if(hantei()) {
            REP(i, n) cout << ans[i];
            cout << endl;
            return 0;
        }
    }

    /* 羊、狼 */
    ans[0] = 'S';
    zenkai = 'S';
    ans[1] = 'W';
    tyosa();
    if(zenkai == ans[0]) {
        if(hantei()) {
            REP(i, n) cout << ans[i];
            cout << endl;
            return 0;
        }
    }

    /* 狼、羊 */
    ans[0] = 'W';
    zenkai = 'W';
    ans[1] = 'S';
    tyosa();
    if(zenkai == ans[0]) {
        if(hantei()) {
            REP(i, n) cout << ans[i];
            cout << endl;
            return 0;
        }
    }

    /* 狼、狼 */
    ans[0] = 'W';
    zenkai = 'W';
    ans[1] = 'W';
    tyosa();
    if(zenkai == ans[0]) {
        if(hantei()) {
            REP(i, n) cout << ans[i];
            cout << endl;
            return 0;
        }
    }    

    cout << "-1" << endl;

    return 0;
}
