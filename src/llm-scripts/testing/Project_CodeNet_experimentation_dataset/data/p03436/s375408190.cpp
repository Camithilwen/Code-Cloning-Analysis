#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

int H,W;
char f[51][51];
bool reach[51][51] = {0};
int vx[4] = {1,0,-1,0};
int vy[4] = {0,1,0,-1};
int white = 0;
int check = -1;

struct corr{
    int x;
    int y;
    int d;
};

queue<corr> Q;

int bfs()
{
    while (!(Q.empty())){
        corr now = Q.front();
        Q.pop();
        int nowx = now.x;
        int nowy = now.y;
        int nowd = now.d;
        
        if (nowx == H-1 && nowy == W-1){
            check = nowd;
            break;
        }
        else {
            for (int i = 0;i < 4;i++){
                corr next;
                next.x = nowx+vx[i];
                next.y = nowy+vy[i];
                next.d = nowd+1;
                if (0 <= next.x && next.x < H && 0 <= next.y && next.y < W && f[next.x][next.y] == '.' && reach[next.x][next.y] == 0){
                    reach[next.x][next.y] = 1;
                    Q.push(next);
                }
            }
        }
    }
    if (check == -1){
        return -1;
    }
    else {
        return check;
    }
}


int main()
{
    cin >> H >> W;
    for (int i = 0;i < H;i++){
        for (int j = 0;j < W;j++){
            cin >> f[i][j];
            if (f[i][j] == '.'){
                white++;
            }
        }
    }
    
    corr start = {0,0,0};
    Q.push(start);
    reach[0][0] = 1;
    
    if (bfs() == -1){
        cout << -1 << endl;
    }
    else {
        cout << white - 1 - bfs() << endl;
    }
}
 
