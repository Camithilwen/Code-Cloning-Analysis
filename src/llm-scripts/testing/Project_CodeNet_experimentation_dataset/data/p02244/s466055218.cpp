#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#define N 8
using namespace std;
int row[N];
bool col[N],dpos[2*N-1],dneg[2*N-1];

void printBoard(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(j==row[i])printf("Q");
      else printf(".");
    }
    printf("\n");
  }
}
void putqueen(int i){
  if(i == N){
    printBoard();
    return;
  }
  if (row[i]!=-1){
      putqueen(i+1);
  }
  else {
    for(int j=0;j<N;j++){
      if(col[j]||dpos[i+j]||dneg[i-j+N-1])continue;
      row[i]=j;
      col[j]=dpos[i+j]=dneg[i-j+N-1]= true;
      putqueen(i+1);
      row[i]=-1;
      col[j]=dpos[i+j]=dneg[i-j+N-1]= false;
    }
  }
}

int main(){
  int n,x,y;
  cin>>n;
  for(int i=0;i<N;i++)row[i]=-1;
  for(int i=0;i<n;i++){
    cin>>x>>y;
    row[x]=y;
    col[y]=dpos[x+y]=dneg[x-y+N-1]=true;
  }
  putqueen(0);

  return 0;
}

