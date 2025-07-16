#include<bits/stdc++.h>
using namespace std;

int H, W, x, y, ans = 0, flag = 0;
queue<int> Qx, Qx_next; queue<int> Qy, Qy_next;

bool can_go(int x, int y){
    return (1 <= x && x <= H && 1 <= y && y<= W);
}

void f(vector<vector<int>>& A, int x, int y){
    if(can_go(x,y)){
        if(A[x][y] == 1){
            flag = 1;
            A[x][y] = -1;
            Qx_next.push(x);
            Qy_next.push(y);
        }
    }
}

void visit(vector<vector<int>>& A, int x, int y){
    f(A, x-1, y);
    f(A, x+1, y);
    f(A, x, y-1);
    f(A, x, y+1);
}

int main(){
    cin >> H >> W;
    vector<vector<int>> A(H+1, vector<int>(W+1, 1));
    char buf;
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j){
            cin >> buf;
            if(buf == '#'){
                A[i][j] = -1; //黒色ならfalse, 白色ならtrue
                Qx.push(i);
                Qy.push(j);
            }
        }
    }
    while(!Qx.empty()){
        x = Qx.front();
        y = Qy.front();
        Qx.pop();
        Qy.pop();
        visit(A, x, y);
        if(Qx.empty()){
            while(!Qx_next.empty()){
                Qx.push(Qx_next.front()); Qx_next.pop();
                Qy.push(Qy_next.front()); Qy_next.pop();
            }
            if(flag == 1)++ans;
            flag = 0;
        }
    }
    cout << ans << endl;
    return 0;
}