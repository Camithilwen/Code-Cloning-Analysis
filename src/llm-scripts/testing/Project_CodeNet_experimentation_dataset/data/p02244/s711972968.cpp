#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;
//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    //sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
int n;
vector<vector<int>> board(8,vector<int>(8,0));

void change(vector<vector<int>> &board,int h,int w,int num){
    REP(i,8){
        board[h][i]+=num;board[i][w]+=num;
    }
    board[h][w]-=num*3;
    //右上
    for(int i=h-1;i>=0;i--){
        if(h-i+w<0 || h-i+w>7)continue;
        board[i][h-i+w]+=num;
    }
    //右下
    for(int i=h+1;i<=7;i++){
        if(h-i+w<0 || h-i+w>7)continue;
        board[i][h-i+w]+=num;
    }
    //左上
    for(int i=h-1;i>=0;i--){
        if(w-(h-i)<0 || w-(h-i)>7)continue;
        board[i][w-(h-i)]+=num;
    }
    //左下
    for(int i=h+1;i<=7;i++){
        if(w-(h-i)<0 || w-(h-i)>7)continue;
        board[i][w-(h-i)]+=num;
    }
}

void setqueen(int q,vector<int>queen,vector<vector<int>>board){
    if(q==8){
        REP(i,8){
            int h=queen[i];
            char ans[]="........";
            ans[h]='Q';
            cout << ans << endl;
        }
        exit(0);
    }
    if(queen[q]!=-1){
        setqueen(q+1,queen,board);
    } else {
        for(int i=0;i<8;i++){
            if(board[q][i]<1){
                queen[q]=i;
                change(board,q,i,1);
                setqueen(q+1,queen,board);
                change(board,q,i,-1);
            }
        }
    }
}

signed main () {
    scanf("%d",&n);
    vector<int> queen(8,-1);
    REP(i,n){
        int a,b;scanf("%d %d",&a,&b);
        //a--;b--;
        queen[a]=b;
        change(board,a,b,1);
    }
    setqueen(0,queen,board);
}
