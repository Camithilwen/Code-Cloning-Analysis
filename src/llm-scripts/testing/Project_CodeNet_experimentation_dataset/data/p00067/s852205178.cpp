#include<iostream>
#include<string.h>
#include<vector>
#include<list>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug " << x << endl;
using namespace std;

int flood(char map[][14], int i, int j){
    if(map[i][j] == '1')
        map[i][j] = '0';
    if(map[i+1][j] == '1')
        flood(map,i+1,j);
    if(map[i][j+1] == '1')
        flood(map,i,j+1);
    if(map[i-1][j] == '1')
        flood(map,i-1,j);
    if(map[i][j-1] == '1')
        flood(map,i,j-1);
    return 1;
}

int main(){
    bool loop = true;
    char map[14][14] = {{'0'}}, s[14];
    while(loop){
        range(i,1,13){
            if(!(cin >> s)) loop = false;
            rep(j,12){
                map[i][j+1] = s[j];
            }
        }
        int ans = 0;
        range(i,1,13){
            range(j,1,13){
                if(map[i][j] == '1')
                    ans += flood(map,i,j);
            }
        }
        if(loop)
            cout << ans << endl;
    }
}