#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int stage[12][12] = {{0}};
    int n;
    int j = 0;
    int x = 0,y = 0,xx = 0;
    for(;;){
        cin >> n;
        if(n == 0)break;
        for(int i = 0;i < n; i++){
            for(j = 0;j < n; j++){
                cin >> stage[i][j];
                x += stage[i][j];
                if(j == n-1){
                    stage[i][n] = x;
                    xx += stage[i][n];
                    x = 0;
                }
            }
        }
        for(int i = 0;i < n; i++){
            for(j = 0;j < n; j++){
                y += stage[j][i];
                if(j == n-1){
                    stage[n][i] = y;
                    y = 0;
                }
            }
        }
        stage[n][n] = xx;
        for(int i = 0;i <= n; i++){
            for(int j = 0;j <= n; j++){
                printf("%5d",stage[i][j]);
            }
            printf("\n");
        }
        x = 0,y = 0,xx = 0;
    }
    return 0;
}