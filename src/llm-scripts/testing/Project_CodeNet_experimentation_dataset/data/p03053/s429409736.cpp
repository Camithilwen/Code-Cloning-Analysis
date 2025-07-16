#include <bits/stdc++.h>  
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define cout(val) cout << (val) << endl
using namespace std;
typedef long long ll;

int main(){
    int h, w;
    char t;
    cin >> h >> w;
    vector<vector<bool>> c(h, vector<bool>(w, false));
    queue<pair<int, int>> que1, que2;
    rep(i, h) rep(j, w){
        cin >> t;
        if(t == '#'){
            que2.push(make_pair(i, j));
            c[i][j] = true;
        }
    }
    pair<int, int> p;
    vector<int> dy ={1,0,-1,0}, dx={0,1,0,-1};
    int tx, ty, result = 0;
    while(!que2.empty()){
        ++result;
        que2.swap(que1);
        while(!que1.empty()){
            p = que1.front();
            que1.pop();
            rep(i, 4){
                ty = p.first + dy[i];
                tx = p.second + dx[i];
                if(ty==-1||tx==-1||ty==h||tx==w||c[ty][tx]) continue;
                que2.push(make_pair(ty, tx));
                c[ty][tx] = true;
            }
        }
    }
    cout(result-1);
}
