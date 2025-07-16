#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl

int sign_x[4] = {1, -1, +1, -1};
int sign_y[4] = {1, -1, -1, +1};

ll board[8][8];

ll queen[8]; // i行目のどこに置いたか

bool in_range(ll x, ll y){
    if(0<=x && x<8 && 0<=y && y<8){
        return true;
    }else{
        return false;
    }
}

// 盤面に置く or 取り除く
// 置く場合 add = 1
// 除く場合 add = -1
void put(ll x, ll y, ll add){
    // cout << "put " << x << " " << y << endl;
    if(add>0){
        queen[y] = x;
    }else{
        queen[y] = -1;
    }

    // row
    FOR(i, 0, 8){
        board[y][i] += add;
    }
    // column
    FOR(i, 0, 8){
        board[i][x] += add;
    }
    // 足しすぎを引く
    board[y][x] -= add;
    // diagonal
    FOR(i, 1, 8){ // 幅
        FOR(j, 0, 4){
            ll nx = x + i * sign_x[j];
            ll ny = y + i * sign_y[j];
            if(in_range(nx, ny)){
                board[ny][nx] += add;
            }
        }
    }
}

// 解答用：クイーンの位置をQで表示する
void printQueen(){
    FOR(y, 0, 8){
        FOR(x, 0, 8){
            if(queen[y]==x){
                cout << 'Q';
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }
}

// ボードの状態を数字で表示する
void debugBoard(){
    FOR(y, 0, 8){
        FOR(x, 0, 8){
            cout << setw(2) << board[y][x] << ' ';
        }
        cout << endl;
    }
}

void setQueen(ll y){
    // pn(y);
    if(y==8){
        printQueen();
        exit(0);
    }

    // すでに置かれている
    if(queen[y]!=-1){
        setQueen(y+1);
    }

    // どこに置こうかな
    FOR(x, 0, 8){
        // 置いてみる
        if(board[y][x]==0){
            put(x, y, 1);
            setQueen(y+1);
            // キャンセル
            put(x, y, -1);
        }        
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N;
    cin >> N;

    FOR(i, 0, 8){
        queen[i] = -1;
    }

    while(N--){
        ll y, x;
        cin >> y >> x;
        put(x, y, 1);
    }

    setQueen(0);
    return 0;
}
