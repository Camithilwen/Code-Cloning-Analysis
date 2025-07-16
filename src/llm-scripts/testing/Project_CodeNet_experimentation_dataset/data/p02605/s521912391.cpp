#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int maxn = 200005;
const int inf = 1000000007;
int x[maxn],yy[maxn];
char c[maxn];
vector<pair<int,int>>vv1;
vector<int>uu,rr,dd,ll;
int cnt = 0 ;
map<int,int>UL,UR,DL,DR,D,L;
vector<int>GG[5*maxn];
void addnodeUL(int num,int y){if(!UL[num])UL[num]=++cnt;GG[UL[num]].push_back(y);}
void addnodeUR(int num,int y){if(!UR[num])UR[num]=++cnt;GG[UR[num]].push_back(y);}
void addnodeDL(int num,int x){if(!DL[num])DL[num]=++cnt;GG[DL[num]].push_back(x);}
void addnodeDR(int num,int x){if(!DR[num])DR[num]=++cnt;GG[DR[num]].push_back(x);}
void addnodeD(int num,int y){if(!D[num])D[num]=++cnt;GG[D[num]].push_back(y);}
void addnodeL(int num,int x){if(!L[num])L[num]=++cnt;GG[L[num]].push_back(x);}
int query(int num,int num2,int mul){
    int ind=lower_bound(GG[num].begin(),GG[num].end(),num2)-GG[num].begin();
    if(ind!=GG[num].size())
        return mul*(GG[num][ind]-num2);
    return inf;
}
int query2(int num,int num2,int mul){
    int ind=lower_bound(GG[num].begin(),GG[num].end(),num2)-GG[num].begin();
    if(ind-1>=0)
        return mul*(num2-GG[num][ind-1]);
    return inf;
}
int queryUL(int num,int y){
    if(!UL[num])return inf;num=UL[num];
    return query(num,y,10);
}
int queryUR(int num,int y){
    if(!UR[num])return inf;num=UR[num];
    return query(num,y,10);
}
int queryDL(int num,int x){
    if(!DL[num])return inf;num=DL[num];
    //cout << num <<endl;
    return query2(num,x,10);
}
int queryDR(int num,int x){
    if(!DR[num])return inf;num=DR[num];
    return query2(num,x,10);
}
int queryD(int num,int y){
    if(!D[num])return inf;num=D[num];
    return query(num,y,5);
}
int queryL(int num,int x){
    if(!L[num])return inf;num=L[num];
    return query(num,x,5);
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i] >>yy[i] >> c[i];
        if(c[i]=='R'){
            addnodeUR(x[i]+yy[i],yy[i]);
            addnodeDR(x[i]-yy[i],yy[i]);
        }else if(c[i]=='L'){
            addnodeDL(x[i]+yy[i],yy[i]);
            addnodeUL(x[i]-yy[i],yy[i]);
            addnodeL(yy[i],x[i]);
        }
        else if(c[i]=='D')
            addnodeD(x[i],yy[i]);
    }
    for(int i=1;i<=cnt;i++)
        sort(GG[i].begin(),GG[i].end());
    int point = inf ;
    for(int i=0;i<n;i++){
        if(c[i]=='U'){
            point=min(point,queryUL(x[i]-yy[i],yy[i]));
            point=min(point,queryUR(x[i]+yy[i],yy[i]));
            point=min(point,queryD(x[i],yy[i]));
            //cout << point << endl;
        }
        if(c[i]=='D'){
            point=min(point,queryDL(x[i]+yy[i],yy[i]));
            point=min(point,queryDR(x[i]-yy[i],yy[i]));
        }
        if(c[i]=='R'){
            point=min(point,queryL(yy[i],x[i]));
            //cout << point << endl;
        }
    }
    if(point==inf)
        cout << "SAFE\n" << endl;
    else
        cout << point <<endl;
    return 0;
}
