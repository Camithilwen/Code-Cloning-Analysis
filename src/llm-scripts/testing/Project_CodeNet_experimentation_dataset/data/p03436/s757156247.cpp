// https://atcoder.jp/contests/abc088/tasks/abc088_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int MAX_N=100;

int h, w;
typedef pair<int, int> P;
vector<vector<char> > maze(MAX_N, vector<char>(MAX_N));
int sx, sy, gx, gy;

vector<vector<ll> > d(MAX_N, vector<ll>(MAX_N));

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

ll bfs(){
    queue<P> que;
    // すべての点をINFで初期化
    rep(x, w)
        rep(y, h) d.at(x).at(y) = INF;
    // スタート地点をqueに入れ、その点距離を0とする
    que.push(P(sx,sy));
    d.at(sx).at(sy) = 0;

    // queが空になるまでループ
    while(que.size()){
        //　キューの先頭を取り出す
        P p = que.front();
        que.pop();
        //　取り出してきた状態がゴールならば探索終了
        if(p.first == gx && p.second == gy) break;
        //　４方向をループ
        rep(i, 4){
            int nx = p.first + dx.at(i), ny = p.second + dy.at(i);

            //　移動が可能かどうかの判定とすでに訪れたことがあるかどうかの判定
            if(0 <= nx && nx < w && 0 <= ny && ny < h && maze.at(nx).at(ny) != '#' && d.at(nx).at(ny) == INF){
                //　移動可能ならばキューに追加、点の距離を+1して確定させる
                que.push(P(nx,ny));
                d.at(nx).at(ny) = d.at(p.first).at(p.second) + 1;
            }
        }
    }
    return d.at(gx).at(gy);
}

int main(){
    //　入力に注意すること!
    //　特に座標を-1することを忘れないこと!
    cin >> h >> w;
    sx = 0; sy = 0; gx = w-1; gy = h-1;
    int road = 0;
    rep(y, h){
        rep(x, w){
            cin >> maze.at(x).at(y);
            if(maze.at(x).at(y) == '.') road++;
        }
    }
    //rep(y, h){rep(x, w){cout << maze.at(x).at(y);}cout << "\n";}cout << "---\n";
    ll answer = bfs();
    //rep(y, h){rep(x, w){cout << d.at(x).at(y);}cout << "\n";}cout << "---\n";
    if(answer == INF) cout << -1 << endl;
    else cout << (road - answer - 1) << endl;
    //cout << maze.at(gx).at(gy) << endl;
}