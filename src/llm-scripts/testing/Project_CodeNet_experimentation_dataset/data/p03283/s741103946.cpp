#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,q;
    cin >> n >> m >> q;
    int a[505][505];
    int c[505][505];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            a[i][j]=0;
            c[i][j]=0;
        }
    }

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        a[x][y] += 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+a[i][j];
        }
    }


    for(int i=0; i<q; i++){
        int x,y;
        cin >> x >> y;
        //cout << c[y][y] << " " <<c[x-1][x-1]<<" " <<c[y][x-1]<< " " <<c[x-1][y] << endl;
        cout << c[y][y]+c[x-1][x-1]-c[y][x-1]-c[x-1][y] << endl;
        }
          
}
