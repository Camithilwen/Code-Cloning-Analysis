#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); i++)
const int MAX = 405;
char grid[MAX][MAX];
int  visited[MAX][MAX];
int h, w;

bool inside(int x, int y)
{
    return 0 <= x && x < h && 0 <= y && y < w;
}

bool check(int x, int y, int a, int b){
    if (!inside(x + a, y + b))
        return false;
    return grid[x][y] != grid[x + a][y + b] && !visited[x + a][y + b];
}

int main()
{
    cin >> h >> w;
    loop(i, 0, h) loop(j, 0, w)
    {
        cin >> grid[i][j];
    }
    long long ans = 0;
    loop(i, 0, h) loop(j, 0, w) {
        if (visited[i][j]) continue;
        queue<pair<int, int>> queue;
        queue.emplace(make_pair(i, j));
        visited[i][j] = 1;
        long long black = 0;
        long long white = 0;
        while(queue.size()){
            pair<int, int> p = queue.front();
            queue.pop();
            if (grid[p.first][p.second] == '#')
                black += 1;
            else 
                white += 1;
            for (int a: {-1, 0, 1}){
                for (int b: {-1, 0, 1}){
                    if(abs(a) == abs(b)) continue;
                    if(check(p.first, p.second, a, b)){
                        queue.emplace(make_pair(p.first + a, p.second + b));
                        visited[p.first + a][p.second + b] = 1;
                    }
                }
            }
        }
        ans += white * black;
    }
    cout << ans << "\n";
    return 0;
}