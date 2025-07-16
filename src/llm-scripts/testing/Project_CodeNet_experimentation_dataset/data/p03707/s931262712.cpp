#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

char s[2003][2003];
char l[2003][2003];
int pr[2003][2003];
int pl[2003][2003];
int pu[2003][2003];
int pd[2003][2003];
int c[2003][2003];
int p[2003];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        cin >> s[i][j];
        l[i][j] = '.';
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(s[i][j] == '1' && l[i][j] == '.'){
        queue<P> que;
        l[i][j] = 'c';
        que.push(P(i, j));
        while(que.size()){
            int x = que.front().first, y = que.front().second;
            que.pop();
            for(int k = 0; k < 4; k++){
                int xx = x + dx[k], yy = y + dy[k];
                if(xx >= 0 && xx < n && yy >= 0 && yy < m && s[xx][yy] == '1' && l[xx][yy] == '.'){
                    if(k == 0) l[xx][yy] = 'u';
                    if(k == 1) l[xx][yy] = 'l';
                    if(k == 2) l[xx][yy] = 'd';
                    if(k == 3) l[xx][yy] = 'r';
                    que.push(P(xx, yy));
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(l[i][j] == 'u') pu[i][j]++;
            if(l[i][j] == 'd') pd[i][j]++;
            pu[i][j + 1] = pu[i][j];
            pd[i][j + 1] = pd[i][j];
        }
    }
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(l[i][j] == 'r') pr[j][i]++;
            if(l[i][j] == 'l') pl[j][i]++;
            pr[j][i + 1] = pr[j][i];
            pl[j][i + 1] = pl[j][i];
        }
    }
    for(int i = n - 1; i >= 0; i--){
        int k = 0;
        for(int j = m - 1; j >= 0; j--){
            if(l[i][j] == 'c') p[j]++;
            k += p[j];
            c[i][j] = k;
        }
    }
    for(int e = 0; e < q; e++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        int ans = c[x1][y1] - c[x2 + 1][y1] - c[x1][y2 + 1] + c[x2 + 1][y2 + 1];
        ans += pu[x1][y2] + pd[x2][y2] + pl[y1][x2] + pr[y2][x2];
        if(y1 > 0) ans -= pu[x1][y1 - 1] + pd[x2][y1 - 1];
        if(x1 > 0) ans -= pl[y1][x1 - 1] + pr[y2][x1 - 1];
        cout << ans << endl;
    }
}