#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    while(1){
        int w, h; cin>>w>>h;
        if(w == 0) return 0;

        int sx, sy, gx, gy; cin>>sx>>sy>>gx>>gy;
        sx--, sy--, gx--, gy--;

        int n; cin>>n;
        vector<vector<int>> board(h, vector<int>(w, 0));
        while(n--){
            int c, d, x, y; cin>>c>>d>>x>>y;
            x--, y--;
            if(d == 0){
                for(int i=y; i<=y+1; i++){
                    for(int j=x; j<=x+3; j++){
                        board[i][j] = c;
                    }
                }
            }
            else{
                for(int i=y; i<=y+3; i++){
                    for(int j=x; j<=x+1; j++){
                        board[i][j] = c;
                    }
                }
            }
        }

        queue<P> que;
        que.push(P(sy, sx));
        int color = board[sy][sx];
        board[sy][sx] = 0;
        if(color == 0){
            cout << "NG" << endl;
            continue;
        }

        while(que.size()){
            int cy, cx;
            tie(cy, cx) = que.front();
            que.pop();

            if(cy == gy && cx == gx){
                cout << "OK" << endl;
                goto END;
            }    

            for(int i=0; i<4; i++){
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if(0 <= ny && ny < h && 0 <= nx && nx < w){
                    if(board[ny][nx] == color){
                        board[ny][nx] = 0;
                        que.push(P(ny, nx));
                    }
                }
            }
        }

        cout << "NG" << endl;
        END:;
    }
}
