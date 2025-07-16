#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    vector<string> s(3);
    rep(i, 3) cin >> s[i];

    int turn = 0;

    while(true){
        if(s[turn].empty()){
            cout << char('A'+turn) << endl;
            return 0;
        }
        int n_turn = s[turn][0] - 'a';
        s[turn].erase(0, 1);
        turn = n_turn;
    }

    return 0;
}