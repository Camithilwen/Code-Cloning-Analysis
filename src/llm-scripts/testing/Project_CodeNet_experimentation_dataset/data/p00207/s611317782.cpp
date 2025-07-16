#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 1010001000
#define loop(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
typedef pair<int, int> i_i;

bool dfs(vector<vector<int> > &g);

int sx, sy, gx, gy;
int w, h;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main()
{

    while (cin >> w >> h, (w|h) ) {
        w++;
        h++;
        vector<vector<int> > graph(w, vector<int>(h, 0));
        cin >> sx >> sy >> gx >> gy;
        int blocks;
        cin >> blocks; 
        loop(i, blocks){
            int c, d, x, y;
            cin >> c >> d >> x >> y;
            if (d) {
                for (int j = x; j < x+2; j++) {
                    for (int k = y; k < y+4; k++) {
                        graph[j][k] = c;
                    }
                }
            } else {
                for (int j = x; j < x+4; j++) {
                    for (int k = y; k < y+2; k++) {
                        graph[j][k] = c;
                    }
                }
            }
        }
        cout << ((dfs(graph))?"OK":"NG") << endl;
    }
    return 0;
}

bool dfs(vector<vector<int> > &g)
{
    int cl = g[sx][sy];
    vector<vector<bool> > check(w, vector<bool>(h, false));
    queue<i_i > q;
    q.push(mp(sx,sy));
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(x == gx && y == gy){
            return true;
        }
        if(check[x][y]){
            continue;
        } else {
            check[x][y] = true;
        }

        loop(i, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 < nx && nx < w && 0 < ny && ny < h){
                if (g[nx][ny] == cl){
                    q.push(mp(nx,ny));
                }
            }
        }

    }
    return false;
}