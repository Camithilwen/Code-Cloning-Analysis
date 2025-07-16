#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct pos{
    int x;
    int y;
};
pos dir[] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

int main(){
    int H, W;
    int depth_max = 0;
    vector<vector<int>> depth;
    queue<pos> dest;
    cin >> H >> W;
    depth.resize(H, vector<int>(W, -1));
    for (int i = 0; i < H; i++){
        string str;
        cin >> str;
        for (int j = 0; j < W; j++){
            char c = str[j];
            if(c == '#'){
                dest.push({i, j});
                depth[i][j] = 0;
            }
        }
    }

    while(dest.size() != 0){
        pos now = dest.front();
        dest.pop();
        for (int i = 0; i < 4; i++){
            pos next = {now.x + dir[i].x, now.y + dir[i].y};
            if(next.x < 0 || H <= next.x || next.y < 0 || W <= next.y){
                continue;
            }
            if(depth[next.x][next.y] != -1){
                if(depth[next.x][next.y] > depth[now.x][now.y] + 1){
                    depth[next.x][next.y] = depth[now.x][now.y] + 1;
                    dest.push(next);
                }
                continue;
            }
            depth[next.x][next.y] = depth[now.x][now.y] + 1;
            dest.push(next);
        }
    }

    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if(depth[i][j] > depth_max){
                depth_max = depth[i][j];
            }
        }
    }
    cout << depth_max << endl;
}