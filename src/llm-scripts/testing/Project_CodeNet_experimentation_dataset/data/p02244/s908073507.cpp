#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

UL buf[9][8][8]={};
UL mask[9]={};
UL ans[8][8];

void put(int x, int y, int k){
 buf[k][x][y]=2;
 for(int xx=0; xx<8; xx++) for(int yy=0; yy<8; yy++){
  if(buf[k][xx][yy]) continue;
  if(xx==x || yy==y || (x+y)==(xx+yy) || (x-y)==(xx-yy))
   buf[k][xx][yy]=1;
 }
}

bool proc(UL k){
 if(k==8){ rep(x,8)rep(y,8) ans[x][y]=buf[8][x][y]; return true; }
 UL y=0; rep(i,8) if(~mask[k] & (1<<i)) y=i;
 mask[k+1] = mask[k] | (1<<y);
 rep(x,8){
  rep(xx,8)rep(yy,8) buf[k+1][xx][yy]=buf[k][xx][yy];
  if(buf[k+1][x][y]) continue;
  put(x,y,k+1);
  if(proc(k+1)) return true;
 }
 return false;
}

int main() {
 mask[0]=0;
 UL K; scanf("%u",&K);
 rep(i,K){
  UL x,y; scanf("%u%u",&y,&x);
  mask[K] |= (1<<y);
  put(x,y,K);
 }
 proc(K);
 rep(y,8){
  rep(x,8) printf((ans[x][y]==2)?"Q":".");
  printf("\n");
 }
 return 0;
}

