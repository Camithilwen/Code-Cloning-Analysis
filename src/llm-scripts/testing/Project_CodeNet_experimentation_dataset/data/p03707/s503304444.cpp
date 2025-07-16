#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long 
#define PB push_back
#define PII pair <long long , long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);

const int maxn = 2e3 + 30;
string a[maxn];
int vertex[maxn][maxn] , er[maxn][maxn] , ed[maxn][maxn];

int main() {
    int n , m , q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(a[i - 1][j - 1] == '1') {
                vertex[i][j]++;
            }
            vertex[i][j] += vertex[i - 1][j] + vertex[i][j - 1] - vertex[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // if(a[i - 1][j - 1] == '1' && a[i - 2][j - 1] == '1') {
            //     ed[i][j]++;
            // }
            if(a[i - 1][j - 1] == '1' && a[i][j - 1] == '1') {
                ed[i][j]++;
            }
            ed[i][j] += ed[i - 1][j] + ed[i][j - 1] - ed[i - 1][j - 1]; 
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // if(a[i - 1][j - 1] == '1' && a[i - 1][j - 2] == '1') {
            //     er[i][j]++;
            // }
            if(a[i - 1][j - 1] == '1' && a[i - 1][j] == '1') {
                er[i][j]++;
            }
            er[i][j] += er[i - 1][j] + er[i][j - 1] - er[i - 1][j - 1]; 
        }
    }
    while(q--) {
        int x1 , y1 , x2 , y2;
        ll p1 = 0 , p2 = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        p1 = vertex[x2][y2] - vertex[x2][y1 - 1] - vertex[x1 - 1][y2] + vertex[x1 - 1][y1 - 1];
        p2 += ed[x2 - 1][y2] - ed[x2 - 1][y1 - 1] - ed[x1 - 1][y2] + ed[x1 - 1][y1 - 1];
        p2 += er[x2][y2 - 1] - er[x1 - 1][y2 - 1] - er[x2][y1 - 1] + er[x1 - 1][y1 - 1];
        cout << p1 - p2 << endl;
    }
}