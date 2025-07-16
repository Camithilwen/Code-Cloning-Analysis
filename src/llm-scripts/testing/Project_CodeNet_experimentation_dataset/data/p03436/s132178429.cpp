#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

ll INF = 1000000000;
vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    int h, w; cin >> h >> w;
    vector <string> s(h);
    int black_cnt = 0;
    rep(i, h){
        cin >> s.at(i);
        for(auto c: s.at(i)){
            if(c == '#') black_cnt ++;
        }
    }

    deque <pair <int, int>> d;
    vector <vector<int>> dist(h, vector<int>(w, INF));

    d.push_back(make_pair(0, 0));
    dist.at(0).at(0) = 0;

    while(!d.empty()){
        auto v = d.front();
        d.pop_front();
        int y, x;
        y = v.first; x = v.second;
        rep(i, 4){
            int ny, nx;
            ny = y + dy.at(i);
            nx = x + dx.at(i);

            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(s.at(ny).at(nx) == '#') continue;
            if(dist.at(ny).at(nx) <= dist.at(y).at(x) + 1) continue;

            dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
            d.push_back(make_pair(ny, nx));
        }
    }

    if(dist.at(h - 1).at(w - 1) == INF){
        cout << -1 << endl;
        return 0;
    }

    //cout << dist.at(h - 1).at(w - 1) << endl;
    cout << h * w - black_cnt - dist.at(h - 1).at(w - 1) - 1 << endl;
}