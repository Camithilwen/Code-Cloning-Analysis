#include<bits/stdc++.h>
using namespace std;
int w,h;
bool isRange(int i,int j){
    return 0<=i && i<w && 0<=j && j<h;
}
int dw[]={-1,0,1,0};
int dh[]={0,1,0,-1};
int dfs(pair<int,int> p,const pair<int,int> g,vector<vector<int>>& grid,int turn){
    if(turn==11)
        return 100;
    int res=100;
    for(int i=0;i<4;i++){
        if(isRange(p.first+dw[i],p.second+dh[i]) && grid[p.first+dw[i]][p.second+dh[i]]==1)
            continue;
        for(auto j=p;isRange(j.first,j.second);j.first+=dw[i] ,j.second+=dh[i]){
            if(j==g){
                return turn;
            }
            if(grid[j.first][j.second]==1){
                grid[j.first][j.second]=0;
                j.first-=dw[i];
                j.second-=dh[i];
                res=min(res,dfs(j,g,grid,turn+1));
                grid[j.first+dw[i]][j.second+dh[i]]=1;
                break;
            }
        }
    }
    return res;
}
int main(){
    while(cin>>w>>h,w){
        pair<int,int> s;
        pair<int,int> g;
        vector<vector<int>> grid(w,vector<int>(h,0));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                int buf;
                cin>>buf;
                grid[j][i]=buf;
                if(buf==2)
                    s=make_pair(j,i);
                if(buf==3)
                    g=make_pair(j,i);
            }

        }
        int res=dfs(s,g,grid,1);
        if(res>11)
            res=-1;
        cout<<res<<endl;
    }
    return 0;
}