#include <iostream>
#include<queue>
#include<string.h>
using namespace std;
#define TATE 1
#define YOKO 0

struct ST {
        int x;
        int y;
    };

int main(void){
    int map[101][101];
    int board[101][101];
    int T[]={0,-1,1,0};
    int Y[]={1,0,0,-1};
    int w,h,xs,xg,ys,yg,n,color,muki,x,y;
    
    ST RE;
    ST GO;
    queue <ST> Q;
    while(1){
        memset(map,0,sizeof(map));
        memset(board,0,sizeof(board));
        cin>>w>>h;
        if(w==0&&h==0)break;
        cin>>xs>>ys>>xg>>yg>>n;
        for(int i=0;i<n;i++){
            cin>>color>>muki>>x>>y;
            if(muki==YOKO){
                for(int j=0;j<4;j++){
                    board[y][x+j]=board[y+1][x+j]=color;
                }
            }
            else{
                for(int j=0;j<4;j++){
                    board[y+j][x]=board[y+j][x+1]=color;
                }
            }
        }
       /* for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }*/
        RE.x=xs;
        RE.y=ys;
        map[ys][xs]=1;
        Q.push(RE);
        int flag=0;
        while(!Q.empty()){
            RE=Q.front();
            Q.pop();
            if(RE.x==xg&&RE.y==yg&&board[RE.y][RE.x]==board[yg][xg]){
                flag=1;
                //cout<<RE.x<<" "<<RE.y<<endl;
                break;
            }
            else{
                for(int i=0;i<4;i++){
                    GO=RE;
                    if(GO.x+Y[i]>0&&GO.y+T[i]>0&&GO.x+Y[i]<101&&GO.y+T[i]<101&&board[GO.y+T[i]][GO.x+Y[i]]==board[GO.y][GO.x]&&map[GO.y+T[i]][GO.x+Y[i]]!=1){
                        GO.x+=Y[i];
                        GO.y+=T[i];
                        map[GO.y][GO.x]=1;
                        Q.push(GO);
                    }
                }
            }
        }
       /* for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }*/
        if(flag==1){
            cout<<"OK"<<endl;
        }
        else{
            cout<<"NG"<<endl;
        }
    }
    
}

