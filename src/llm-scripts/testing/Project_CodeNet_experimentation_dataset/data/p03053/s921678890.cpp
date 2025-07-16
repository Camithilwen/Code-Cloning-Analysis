#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep01(i, n) for(int i = 0; i < (n) + 1; i++)
#define rep10(i, n) for(int i = 1; i < (n); i++)
#define rep11(i, n) for(int i = 1; i < (n) + 1; i++)
#define all(a) (a).begin(), (a).end()
typedef long long int ll;
typedef struct { int x; int y; } Pos;
using namespace std;

const int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int time_ = 0;
int H, W;
bool cont = false;
vector<vector<char>> a;
queue<Pos> remq;
queue<Pos> nxtq;
int main() {
    cin >> H >> W;
    a = vector<vector<char>>(W + 1, vector<char>(H + 1));
    rep11(y, H) rep11(x, W) {
        cin >> a[x][y];
        if (a[x][y] == '#') nxtq.push(Pos{ x, y });
    }
    while (0 < nxtq.size()) {
        remq = queue<Pos>(nxtq);
        nxtq = queue<Pos>();
        cont = false;
        while (0 < remq.size()) {
            Pos ref = remq.front();
            remq.pop();
            rep(i, 4) {
                Pos chk = Pos{ ref.x + dx[i], ref.y + dy[i] };
                if (chk.x <= 0 || chk.x > W || chk.y <= 0 || chk.y > H) continue;
                if (a[chk.x][chk.y] == '.') {
                    a[chk.x][chk.y] = '#';
                    nxtq.push(Pos{ chk.x, chk.y });
                    cont = true;
                }
            }
        }
        if (cont) time_++;
    }  
    cout << time_ << endl;
    return 0;
}