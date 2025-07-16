#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  string ans;
  int zyoge=abs(ty-sy);
  int sayu=abs(tx-sx);
  char rl,ud;
  //1
  if(tx-sx>=0){
    rl='R';
  }else{
    rl='L';
  }
  if(ty-sy>=0){
    ud='U';
  }else{
    ud='D';
  }
  int i,j;
  for(i=0;i<zyoge;i++){
    ans=ans+ud;
  }
  for(j=0;j<sayu;j++){
    ans+=rl;
  }
  //2
  if(tx-sx>=0){
    rl='L';
  }else{
    rl='R';
  }
  if(ty-sy>=0){
    ud='D';
  }else{
    ud='U';
  }
  for(i=0;i<zyoge;i++){
    ans=ans+ud;
  }
  for(j=0;j<sayu;j++){
    ans+=rl;
  }
  //3
  if(tx-sx>=0){
    rl='R';
    ans+='D';
  }else{
    rl='L';
    ans+='D';
  }
  if(ty-sy>=0){
    ud='U';
  }else{
    ud='D';
  }
  for(j=0;j<sayu+1;j++){
    ans+=rl;
  }
  for(i=0;i<zyoge+1;i++){
    ans=ans+ud;
  }
  //4
  if(tx-sx>=0){
    ans+='L';
    rl='L';
    ans+='U';
  }else{
    ans+='R';
    rl='R';
    ans+='U';
  }
  if(ty-sy>=0){
    ud='D';
  }else{
    ud='U';
  }
  for(j=0;j<sayu+1;j++){
    ans+=rl;
  }
  for(i=0;i<zyoge+1;i++){
    ans=ans+ud;
  }
   if(tx-sx>=0){
    ans+='R';
  }else{
    ans+='L';
  }
  cout << ans;
}