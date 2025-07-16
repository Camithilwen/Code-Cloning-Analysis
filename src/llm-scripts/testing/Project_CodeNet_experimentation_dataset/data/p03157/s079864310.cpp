#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;


ll dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
ll counterb=0,counterw=0;
void dfs(ll x,ll y,ll H, ll W,vector<vector<bool>> &field,vector<vector<bool>> &check){
    check[x][y]=1;
    if(field[x][y]==1){counterb++;}
    if(field[x][y]==0){counterw++;}
    bool meter=(x+y+field[x][y])%2;
    for(int i=0;i<4;i++){if(x+dx[i]>=0&&x+dx[i]<H&&y+dy[i]>=0&&y+dy[i]<W){
        if(check[x+dx[i]][y+dy[i]]==0&&(x+y+dx[i]+dy[i]+field[x+dx[i]][y+dy[i]])%2==meter){
            dfs(x+dx[i],y+dy[i],H,W,field,check);
        };}
    ;}
    

}




int main(){
ll H;
cin >> H;
ll W;
cin >> W;
vector<vector<bool>> field(H, vector<bool>(W, 0));
vector<vector<bool>> check(H, vector<bool>(W, 0));
for(int i=0;i<H;i++){
 for(int j=0;j<W;j++){
     char k;
     cin>>k;
     if(k=='#'){field[i][j]=1;}
 ;}
;}
    ll ans=0;
for(ll i=0;i<H;i++){
 for(ll j=0;j<W;j++){
     
     if(check[i][j]==0){
         dfs(i,j,H,W,field,check);ans+=counterb*counterw;
         counterb=0;counterw=0;
     }
     
 ;}
;}
cout<<ans<<endl;
return 0;


}  

