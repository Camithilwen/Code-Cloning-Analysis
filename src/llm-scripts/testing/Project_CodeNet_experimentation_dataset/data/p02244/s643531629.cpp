#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()
 
using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
 
const ll MOD  = 1e9+7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

bool isgood(vector<string> bd, int x, int y){
    int cnt = 0;

    //lateral direction
    rep(i, 8)if(bd[x][i] == 'Q')cnt++;
    if(cnt != 1)return false;

    //longitudinal direction
    cnt = 0;
    rep(i, 8)if(bd[i][y] == 'Q')cnt++;
    if(cnt != 1)return false;

    // //diagonally upward
    cnt = 0;
    for(int i = 1; x+i < 8 && y+i < 8; ++i){
        if(bd[x+i][y+i] == 'Q')return false;
    }
    for(int i = 1; x-i >= 0 && y-i >= 0; ++i){
        if(bd[x-i][y-i] == 'Q')return false;
    }

    //diagonally downward
    cnt = 0;
    for(int i = 1; x+i < 8 && y-i >= 0; ++i){
        if(bd[x+i][y-i] == 'Q')return false;
    }
    for(int i = 1; x-i >= 0 && y+i < 8; ++i){
        if(bd[x-i][y+i] == 'Q')return false;
    }

    return true;
}

int main(){
    ll k;
    cin >> k;

    vector<int> c(8, -1);
    rep(i, k){
        int r;
        cin >> r;
        cin >> c[r];
    }

    vector<ll> ary(8);
    iota(ALL(ary), 0);

    vector<string> board(8);
    fill(ALL(board), "........");

    do{
        vector<string> board_cp = board;
        vector<int> pos(8);

        rep(i, 8){
            if(c[i] < 0)pos[i] = ary[i];
            else pos[i] = c[i];

            board_cp[i][pos[i]] = 'Q';
        }

        bool isOk = true;

        rep(i, 8){
            isOk &= isgood(board_cp, i, pos[i]);
        }

        
        if(isOk){
            board = board_cp;
            break;
        }

    }while(next_permutation(ALL(ary)));

    rep(i, 8){
        rep(j, 8)cout << board[i][j];
        cout << endl;
    }
}
