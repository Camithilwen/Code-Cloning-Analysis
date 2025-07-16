#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
typedef pair<int, int> P;
typedef pair<P, P> PP;
vector<PP> ans;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w; cin >> h >> w;
    int a[510][510];
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }

    rep(i, h) {
        rep(j, w - 1) {
            if(a[i][j] % 2 == 1) {
                a[i][j]--;
                a[i][j + 1]++;
                ans.push_back({{i , j}, {i, j + 1}});
            }
        }
    }
    rep(i, h - 1) {
        if(a[i][w - 1] % 2 == 1) {
            a[i][w - 1]--;
            a[i + 1][w - 1]++;
            ans.push_back({{i , w - 1}, {i + 1, w - 1}});
        }
    }
    cout << ans.size() << endl;
    for(auto e: ans) {
        cout << e.first.first  + 1 << " " << e.first.second + 1 << " " << e.second.first + 1 << " " << e.second.second + 1 << endl;
        
    }


    return 0;
}
