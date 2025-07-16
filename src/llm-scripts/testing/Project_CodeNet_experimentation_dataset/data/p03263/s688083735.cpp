#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int h, w;
struct xydata {
    int px; int py; int nex; int ney;
};

int main() {
    cin >> h >> w;
    vector< vector<int> > amap(h, vector<int>(w, 0));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            cin >> amap.at(i).at(j);
        }
    }

    int n = 0;
    vector<xydata> xyvec;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(amap.at(i).at(j)%2 != 0) {
                // そのマスが奇数ならまずは周囲を確認する
                bool flg = false;
                for(int k = 0; k < 4; ++k) {
                    int nx = j+dx[k]; int ny = i+dy[k];
                    if(nx >= 0 && nx < w && ny >= 0 && ny < h) {
                        if(amap.at(ny).at(nx)%2 != 0) {
                            flg = true;
                            n++;
                            xydata indata;
                            indata.px = j; indata.py = i;
                            indata.nex = nx; indata.ney = ny;
                            xyvec.emplace_back(indata);
                            amap.at(i).at(j)--;
                            amap.at(ny).at(nx)++;
                            break;
                        }
                    }
                }
                if(!flg) {
                    for(int k = 2; k < 4; ++k) {
                        int nx = j+dx[k]; int ny = i+dy[k];
                        if(nx >= 0 && nx < w && ny >= 0 && ny < h) {
                            n++;
                            xydata ndata;
                            ndata.px = j; ndata.py = i;
                            ndata.nex = nx; ndata.ney = ny;
                            xyvec.emplace_back(ndata);
                            amap.at(i).at(j)--;
                            amap.at(ny).at(nx)++;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << n << endl;
    for(int i = 0; i < n; ++i) {
        xydata ans = xyvec.at(i);
        cout << ans.py+1 << " " << ans.px+1 << " " << ans.ney+1 << " " << ans.nex+1 << endl;
    }
}