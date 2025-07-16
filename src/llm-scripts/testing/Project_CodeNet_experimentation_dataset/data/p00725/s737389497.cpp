#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <limits>
#include <map>
#include <queue>
#include <stack>
#include <vector>

#define FOR(i,k,n) for(int (i) = (k); (i) < (n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x,y) cerr << #x << ": " << x << ", " << #y << ": " << y << endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<i_i, int> p_i;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
template<class T> using vv=vector<vector<T>>;
typedef deque<int> di;
typedef deque<deque<int>> ddi;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
short d[22][22][11] ={};
int ans = 100;

void dfs(i_i p, int t) {
    if(t > 10) return;
    rep(i,4){
        i_i m = p;
        if(d[m.first+dx[i]][m.second+dy[i]][t] == 2) continue; 
        while(1) {
            if(d[m.first+dx[i]][m.second+dy[i]][t] == 0) break;
            if(d[m.first+dx[i]][m.second+dy[i]][t] == 4) {
                ans = min(ans,t); 
                break;
            }
            if(d[m.first+dx[i]][m.second+dy[i]][t] == 2) {
                rep(j,22) {
                    rep(k,22) {
                        d[j][k][t+1] = d[j][k][t];
                    }
                }
                d[m.first+dx[i]][m.second+dy[i]][t+1] = 1;
                dfs(make_pair(m.first,m.second),t+1); 
                break;
            } else {
                m.first += dx[i], m.second += dy[i];
            }
        }
    }
}

int main() {
    while(1) {
        int w,h;
        i_i s;
        ans = 100;
        memset(d,0,sizeof(d)); 
        cin >> w >> h;
        if(w==0) break;
        FOR(j,1,h+1) {
            FOR(i,1,w+1) {
                cin >> d[i][j][1];
                if(d[i][j][1] == 2){s = make_pair(i,j); d[i][j][1] = 0; }
                d[i][j][1] += 1;
            }
        }
        dfs(s,1);
        ans == 100? cout << -1 << endl:cout << ans << endl;
    }
    return 0;
    }