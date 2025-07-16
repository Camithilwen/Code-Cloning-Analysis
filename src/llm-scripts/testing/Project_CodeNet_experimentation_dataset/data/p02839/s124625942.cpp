#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int h,w;
    scanf("%d %d",&h, &w);
    int aaiDeffer[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            scanf("%d", &aaiDeffer[i][j]);
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int x;
            scanf("%d", &x);
            aaiDeffer[i][j] = abs(aaiDeffer[i][j] - x);  //aaiDeffer[i][j]に2整数の差を入れる
        }
    }
    
    vector<vector<vector<char>>> vvviCanValue(h, vector<vector<char>>(w, vector<char>(12801, 0)));  //(i,j)が0~12800の値を取れるか
    vvviCanValue[0][0][aaiDeffer[0][0]] = 1;
    for(int i = 1; i < h; i++){
        for(int j = 0; j < 12801; j++){
            if(vvviCanValue[i - 1][0][j] == 1){
                int x = aaiDeffer[i][0];
                vvviCanValue[i][0][abs(j - x)] = 1;
                vvviCanValue[i][0][j + x] = 1;
            }
        }
    }
  
    for(int i = 1; i < w; i++){
        for(int j = 0; j < 12801; j++){
            if(vvviCanValue[0][i - 1][j] == 1){
                int x = aaiDeffer[0][i];
                vvviCanValue[0][i][abs(j - x)] = 1;
                vvviCanValue[0][i][j + x] = 1;
            }
        }
    }
  
    for(int i = 1; i < h; i++){
        for(int j = 1; j < w; j++){
            for(int k = 0; k < 12801; k++){
                if(vvviCanValue[i - 1][j][k] == 1 || vvviCanValue[i][j - 1][k] == 1){
                    int x = aaiDeffer[i][j];
                    vvviCanValue[i][j][abs(k - x)] = 1;
                    vvviCanValue[i][j][k + x] = 1;
                }
            }
        }
    }
    for(int i = 0; i < 12801; i++){
        if(vvviCanValue[h-1][w-1][i] == 1){
            printf("%d",i);
            break;
        }
    }
    return 0;
}
