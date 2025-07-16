#include <bits/stdc++.h>
using namespace std;
int main(void){
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    std::map<pair<int,int>, int> seen;
    int x=sx,y=sy;
    for (int i=0;i<2;i++) {
    seen[pair(tx,ty)]=0;
    seen[pair(x,y)]++;
    while (1) {
        if (x<tx&&seen[pair(x+1,y)]==0) {
            cout<<"R";
            seen[pair(x+1,y)]++;
            x++;
        } else if (y<=ty&&seen[pair(x,y+1)]==0) {
            cout<<"U";
            seen[pair(x,y+1)]++;
            y++;
        } else if (seen[pair(x-1,y)]==0) {
            cout<<"L";
            seen[pair(x-1,y)]++;
            x--;
        } else if (seen[pair(x,y-1)]==0) {
            cout<<"D";
            seen[pair(x,y-1)]++;
            y--;
        }
        if (x==tx&&y==ty) {
            break;
        }
    }
    seen[pair(sx,sy)]=0;
    //cout<<endl;
    while (1) {
        if (x>sx&&seen[pair(x-1,y)]==0) {
            cout<<"L";
            seen[pair(x-1,y)]++;
            x--;
        } else if (y>=sy&&seen[pair(x,y-1)]==0) {
            cout<<"D";
            seen[pair(x,y-1)]++;
            y--;
        } else if (seen[pair(x+1,y)]==0) {
            cout<<"R";
            seen[pair(x+1,y)]++;
            x++;
        } else if (seen[pair(x,y+1)]==0) {
            cout<<"U";
            seen[pair(x,y+1)]++;
            y++;
        }
        if (x==sx&&y==sy) {
            break;
        }
    }
    //cout<<endl;
    }
    cout<<endl;
}