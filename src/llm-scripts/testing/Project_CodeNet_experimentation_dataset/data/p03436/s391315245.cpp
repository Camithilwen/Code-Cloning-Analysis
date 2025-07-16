#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
#define v(i) vector<i>
#define vv(i) vector<vector<i>>
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換

int main() {
    int h, w;
    cin >> h >> w;
    char s[h+1][w+1];
    int cnt = 0;
    int visited[h+1][w+1];
    int a[] = {1,0,-1,0};
    int b[] = {0,1,0,-1};
    rep(i, h) {
        rep(j, w) {
            cin >> s[i][j];
            if(s[i][j] == '.')
                cnt++;
                visited[i][j] = -1;
        }
    }
queue<pair<int,int>> que;
visited[0][0] = 0;
que.push(make_pair(0,0));
while(!que.empty()){
  pair<int,int> now = que.front();
    //int ny=que.front().first,nx=que.front().second;
    que.pop();
  int ny=now.first,nx=now.second;

    rep(i,4){
        int y = ny+a[i],x = nx + b[i];
        if(y<0 || y>=h || x<0 || x>=w || visited[y][x] != -1) continue;
        if(s[y][x] == '#') continue;
        visited[y][x] = visited[ny][nx] + 1;
        que.push(make_pair(y,x));
    }
}
if(visited[h-1][w-1] == -1) cout<<-1<<endl;
else
cout<<cnt - visited[h-1][w-1] - 1<<endl;
    return 0;
}
