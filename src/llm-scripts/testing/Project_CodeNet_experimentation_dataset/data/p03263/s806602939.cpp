#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int lr[4]={1, 0, -1, 0};
int ud[4]={0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int> > A(H, vector<int>(W));
    for(int h=0; h<H; h++) {
        for(int w=0; w<W; w++) {
            cin >> A[h][w];
        }
    }
    int dir=0;
    queue<pair<int, int> > que;
    que.push(make_pair(0, 0));
    vector<vector<bool> > seen(H, vector<bool>(W, false));
    vector<pair<pair<int, int>, pair<int, int> > > ans;
    while(!que.empty()) {
        pair<int, int> hw=que.front(); que.pop();
        int curh=hw.first, curw=hw.second;
        seen[curh][curw]=true;
        bool flag=false;
        if(A[curh][curw]%2) {
            flag=true;
        }
        int tmpd=dir;
        while(tmpd-dir<4) {
            if(curh+ud[tmpd%4]<0 || curh+ud[tmpd%4]>=H || curw+lr[tmpd%4]<0 || curw+lr[tmpd%4]>=W) {
                tmpd++;
                continue;
            }
            if(seen[curh+ud[tmpd%4]][curw+lr[tmpd%4]]) {
                tmpd++;
                continue;
            }
            if(flag) {
                A[curh+ud[tmpd%4]][curw+lr[tmpd%4]]++;
                ans.push_back(make_pair(make_pair(curh, curw), make_pair(curh+ud[tmpd%4], curw+lr[tmpd%4])));
            }
            que.push(make_pair(curh+ud[tmpd%4], curw+lr[tmpd%4]));
            dir = tmpd%4;
            break;
        }
    }
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i].first.first+1 << " " << ans[i].first.second+1 << " " << ans[i].second.first+1 << " " << ans[i].second.second+1 << endl;
    }

    return 0;
    
}