// TeamNichoen
// g++ -O2 -Wall -Wextra -Wshadow problemA.cpp 

#include "bits/stdc++.h"

using namespace std;

typedef long long int LL;
typedef long long int ll;

#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int solve(vector<vector<int> > &mp,int sx,int sy,int gx,int gy,int dir,int dep){
    if(dep>=11){
        return 9999;
    }
    if(mp[sx+dx[dir]][sy+dy[dir]]==0)
    {
        while(mp[sx+dx[dir]][sy+dy[dir]]==0){
            sx+=dx[dir];
            sy+=dy[dir];
            if(sx==gx&&sy==gy){
                return 0;//goal
            }
        }

        if(mp[sx+dx[dir]][sy+dy[dir]]==1){
            mp[sx+dx[dir]][sy+dy[dir]]=0;
            int mini=99999;
            REP(i,4){
                int val=solve(mp,sx,sy,gx,gy,i,dep+1)+1;
                if(val<mini){
                    mini=val;
                }
            }
            mp[sx+dx[dir]][sy+dy[dir]]=1;
            return mini;
        }else{
            return 9999;
        }
    }
    else
    {
        return 9999;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(true){

    int w,h;
    cin>>w>>h;
    if(w==0){
        break;
    }

    vector<vector<int> > mp(w+2,vector<int>(h+2,-1));

    int startx;
    int starty;
    int goalx;
    int goaly;
    REP(j,h){
        REP(i,w){
            int hoge;
            cin>>hoge;
            if(hoge==0||hoge==1)
            {
                mp[i+1][j+1]=hoge;
            }else
            if(hoge==2){
                mp[i+1][j+1]=0;
                startx=i+1;
                starty=j+1;
            }else{
                mp[i+1][j+1]=0;
                goalx=i+1;
                goaly=j+1;

            }
        }   
    }

    int mini=99999;
    REP(i,4){
        int val=solve(mp,startx,starty,goalx,goaly,i,0)+1;
        if(val<mini){
            mini=val;
        }
    }
    if(mini>10){
        cout<<-1<<endl;
    }else{
    cout<<mini<<endl;
    }
    }
}

