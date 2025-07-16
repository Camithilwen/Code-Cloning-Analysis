#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

// 累積和（2次元）
template <class T>
class cumulativeSum
{
private:
    int ny, nx;
    vector<vector<T> > sum;
public:
    cumulativeSum(const vector<vector<T> >& a)
    {
        ny = a.size();
        nx = a[0].size();
        sum.assign(ny+1, vector<T>(nx+1, 0));
        for(int i=0; i<ny; ++i){
            for(int j=0; j<nx; ++j){
                sum[i+1][j+1] = a[i][j] + sum[i][j+1] + sum[i+1][j] - sum[i][j];
            }
        }
    }
    T getSum(int y1, int x1, int y2, int x2)
    {
        y1 = max(y1, 0);
        x1 = max(x1, 0);
        y2 = min(y2, ny-1);
        x2 = min(x2, nx-1);
        if(y1 > y2 || x1 > x2)
            return 0;
        return sum[y2+1][x2+1] - sum[y1][x2+1] - sum[y2+1][x1] + sum[y1][x1];
    }
};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int> > s(h, vector<int>(w, 0));
    int ey, ex;
    for(int y=0; y<h; ++y){
        for(int x=0; x<w; ++x){
            char c;
            cin >> c;
            if(c == 'E'){
                ey = y;
                ex = x;
            }
            else if(c == 'o'){
                s[y][x] = 1;
            }
        }
    }
    cumulativeSum<int> cs(s);

    int up    = ey;
    int down  = h - 1 - ey;
    int left  = ex;
    int right = w - 1 - ex;
    vector<vector<vector<vector<int> > > > dp(up+1, vector<vector<vector<int> > >(down+1, vector<vector<int> >(left+1, vector<int>(right+1, 0))));
    int ans = 0;
    for(int u=0; u<=up; ++u){
        for(int d=0; d<=down; ++d){
            for(int l=0; l<=left; ++l){
                for(int r=0; r<=right; ++r){
                    ans = max(ans, dp[u][d][l][r]);

                    int y1 = max(ey - u, d);
                    int y2 = min(ey + d, h - 1 - u);
                    if(ex - 1 - l >= r)
                        dp[u][d][l+1][r] = max(dp[u][d][l+1][r], dp[u][d][l][r] + cs.getSum(y1, ex - 1 - l, y2, ex - 1 - l));
                    if(ex + 1 + r <= w - 1 - l)
                        dp[u][d][l][r+1] = max(dp[u][d][l][r+1], dp[u][d][l][r] + cs.getSum(y1, ex + 1 + r, y2, ex + 1 + r));

                    int x1 = max(ex - l, r);
                    int x2 = min(ex + r, w - 1 - l);
                    if(ey - 1 - u >= d)
                        dp[u+1][d][l][r] = max(dp[u+1][d][l][r], dp[u][d][l][r] + cs.getSum(ey - 1 - u, x1, ey - 1 - u, x2));
                    if(ey + 1 + d <= h - 1 - u)
                        dp[u][d+1][l][r] = max(dp[u][d+1][l][r], dp[u][d][l][r] + cs.getSum(ey + 1 + d, x1, ey + 1 + d, x2));
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}