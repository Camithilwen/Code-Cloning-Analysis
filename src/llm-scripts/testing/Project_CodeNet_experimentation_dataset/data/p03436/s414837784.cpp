#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}

vector<vector<char>> d(100, vector<char>(100));
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main(){
    int r,c;
    cin >> r >> c;
    int sy = 0, sx = 0;
    int gx, gy;
    gx = r-1, gy = c-1;
    int cnt_w = 0;
    rep(i, r){
        rep(j, c){
            cin >> d.at(i).at(j);
            if(d[i].at(j) == '.'){
                cnt_w++;
            }
        }
    }
    vvi dep(r, vi(c, -1));
    dep.at(sy).at(sx) = 0;

    queue<pair<int, int> > que;
    que.push(make_pair(sy, sx));

    while(!que.empty()){
        pair<int, int> pos = que.front();
        que.pop();
        int x = pos.second;
        int y = pos.first;

        rep(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > c-1 || ny < 0 || ny > r-1)
            continue;
            if(d.at(ny).at(nx) == '#')
            continue;

            if(dep.at(ny).at(nx) == -1){
                que.push(make_pair(ny, nx));
                dep.at(ny).at(nx) = dep.at(y).at(x) + 1;
            }
        }
    }
    /*
    rep(i, r){
        rep(j, c){
            printf("%3d", dep.at(i).at(j));
        }
        cout << endl;
    }
    */
    if(dep.at(gx).at(gy) == -1) {
        cout << -1 << endl;
    }
    else {
        cout << cnt_w - dep.at(gx).at(gy)-1 << endl;
    }
    return 0;
}