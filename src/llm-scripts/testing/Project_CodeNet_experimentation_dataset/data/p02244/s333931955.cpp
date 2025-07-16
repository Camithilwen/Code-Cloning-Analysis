#include<bits/stdc++.h>
using namespace std;
#define int long long
string s[8];
int ng[8][8];
bool flg;
void dfs(int r){
  if(r==8){
    flg=1;
    return;
  }
  for(int c=0;c<8;c++){
    if(s[r][c]=='Q'){
      dfs(r+1);
      return;
    }
  }
  for(int c=0;c<8;c++){
    if(ng[r][c]) continue;
    s[r][c]='Q';
    for(int j=0;j<8;j++){
      if(r+j<8 ) ng[r+j][c]++;
      if(r-j>=0) ng[r-j][c]++;
      if(c+j<8 ) ng[r][c+j]++;
      if(c-j>=0) ng[r][c-j]++;
      if(r+j<8 &&c+j<8 ) ng[r+j][c+j]++;
      if(r-j>=0&&c+j<8 ) ng[r-j][c+j]++;
      if(r-j>=0&&c-j>=0) ng[r-j][c-j]++;
      if(r+j<8 &&c-j>=0) ng[r+j][c-j]++;
    }
    dfs(r+1);
    if(flg) return;
    s[r][c]='.';
    for(int j=0;j<8;j++){
      if(r+j<8 ) ng[r+j][c]--;
      if(r-j>=0) ng[r-j][c]--;
      if(c+j<8 ) ng[r][c+j]--;
      if(c-j>=0) ng[r][c-j]--;
      if(r+j<8 &&c+j<8 ) ng[r+j][c+j]--;
      if(r-j>=0&&c+j<8 ) ng[r-j][c+j]--;
      if(r-j>=0&&c-j>=0) ng[r-j][c-j]--;
      if(r+j<8 &&c-j>=0) ng[r+j][c-j]--;
    }
  }
}
signed main(){
  for(int i=0;i<8;i++) s[i]=string(8,'.');
  int n;
  cin>>n;
  memset(ng,0,sizeof(ng));
  for(int i=0;i<n;i++){
    int r,c;
    cin>>r>>c;
    s[r][c]='Q';
    for(int j=0;j<8;j++){
      if(r+j<8 ) ng[r+j][c]++;
      if(r-j>=0) ng[r-j][c]++;
      if(c+j<8 ) ng[r][c+j]++;
      if(c-j>=0) ng[r][c-j]++;
      if(r+j<8 &&c+j<8 ) ng[r+j][c+j]++;
      if(r-j>=0&&c+j<8 ) ng[r-j][c+j]++;
      if(r-j>=0&&c-j>=0) ng[r-j][c-j]++;
      if(r+j<8 &&c-j>=0) ng[r+j][c-j]++;
    }
  }
  flg=0;
  dfs(0);
  for(int i=0;i<8;i++) cout<<s[i]<<endl;
  return 0;
}