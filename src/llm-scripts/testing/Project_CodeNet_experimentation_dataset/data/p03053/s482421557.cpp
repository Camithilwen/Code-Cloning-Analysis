//Darker and Darker
#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};
typedef pair<int, int> PII;


int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grah(h);
    rep(i, h) cin >> grah.at(i);
    queue<PII> q;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    rep(i,h) rep(j, w){
        if(grah.at(i).at(j) == '#'){
            q.emplace(i, j);
            dist.at(i).at(j) = 0;
        }

    }

    while(!q.empty()){
        PII v = q.front();
        q.pop();
        rep(i, 4){
            int ny = v.first + dy.at(i);
            int nx = v.second + dx.at(i);
            if(ny >= 0 && nx >= 0 && ny < h && nx < w && dist.at(ny).at(nx) == -1 && grah.at(ny).at(nx) != '#'){
                dist.at(ny).at(nx) = dist.at(v.first).at(v.second) + 1;
                q.emplace(ny, nx);
            }
        }
    }
    int res = 0;
    rep(i, h) rep(j, w){
        res = max(res, dist.at(i).at(j));
    }

    cout << res << endl;

    return 0;

}
