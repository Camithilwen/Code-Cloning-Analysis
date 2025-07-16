#include <iostream>
#include <algorithm>
using namespace std;

int v[22][22], W, H, turn, m;

void dfs(int h, int w){
    if(turn < 11){
        turn++;
    if(v[h][w+1]==0 || v[h][w+1]==3){
        for(int i=1; w+i<W; i++){
            if(v[h][w+i]==3 && turn<m){
                m = turn;
                break;
            }
            if(v[h][w+i]==1){
                v[h][w+i]=0;
                dfs(h, w+i-1);
                v[h][w+i]=1;
                break;
            }
        }
    }
    if(v[h][w-1]==0 || v[h][w-1]==3){
        for(int i=1; w-i>=0; i++){
            if(v[h][w-i]==3 && turn<m){
                m = turn;
                break;
            }
            if(v[h][w-i]==1){
                v[h][w-i]=0;
                dfs(h, w-i+1);
                v[h][w-i]=1;
                break;
            }
        }
    }
    if(v[h+1][w]==0 || v[h+1][w]==3){
        for(int i=1; h+i<H; i++){
            if(v[h+i][w]==3 && turn<m){
                m = turn;
                break;
            }
            if(v[h+i][w]==1){
                v[h+i][w]=0;
                dfs(h+i-1, w);
                v[h+i][w]=1;
                break;
            }
        }
    }
    if(v[h-1][w]==0 || v[h-1][w]==3){
        for(int i=1; h-i>=0; i++){
            if(v[h-i][w]==3 && turn<m){
                m = turn;
                break;
            }
            if(v[h-i][w]==1){
                v[h-i][w]=0;
                dfs(h-i+1, w);
                v[h-i][w]=1;
                break;
            }
        }
    }
    turn--;
    }
}

int main(void){
    int h1, w1;
    while(cin>>W>>H){
        if(W==0 && H==0)    break;
        m = 11;
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cin >> v[i][j];
                if(v[i][j]==2){
                    h1=i; w1=j;
                    v[i][j]=0;
                }
            }
        }
        turn = 0;
        dfs(h1, w1);
        if(m==11)cout << -1 << endl;
        else cout << m << endl;
    }
    return 0;
}
