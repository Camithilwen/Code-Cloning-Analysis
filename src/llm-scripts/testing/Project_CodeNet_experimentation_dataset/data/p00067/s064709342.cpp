#include<cstdio>
#include<iostream>
using namespace std;
char masu[50][50] = {{0}};
void saiki(int x,int y){
    masu[y][x] = '0';

    if(masu[y+1][x] == '1') saiki(x,y+1);
    if(masu[y-1][x] == '1') saiki(x,y-1);
    if(masu[y][x+1] == '1') saiki(x+1,y);
    if(masu[y][x-1] == '1') saiki(x-1,y);
}
int main(){
    while(1){
        int cnt = 0;
        for(int i = 0; i < 12; i++){
            if(scanf("%s",masu[i]) == EOF)goto a;
        }
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 12; j++){
                if(masu[i][j] == '1'){
                    saiki(j,i);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    a:;
    return 0;
}