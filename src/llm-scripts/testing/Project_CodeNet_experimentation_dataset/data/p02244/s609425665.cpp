#include<bits/stdc++.h>
using namespace std;
int w[8],h[8],x1[15],x2[15],f=0;
char m[8][8],ans[8][8];
void fs(int n=0){
  if(f)return;
  if(n==8){
    f=1;
    for(int i=0;i<8;i++)
      for(int j=0;j<8;j++)
	ans[i][j]=m[i][j];
    return;
  }
  if(h[n]==1)fs(n+1);
  else{
    for(int i=0;i<8;i++){
      if(w[i]+x1[7+i-n]+x2[n+i]==0){
	m[n][i]='Q';
	w[i]=x1[7+i-n]=x2[n+i]=1;
	fs(n+1);
	m[n][i]='.';
	w[i]=x1[7+i-n]=x2[n+i]=0;
      }
    }
  }
}

int main(){

  for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
      m[i][j]='.';
  
  int n,a,b;
  
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    m[a][b]='Q';
    h[a]=w[b]=1;
    x1[7+b-a]=1;
    x2[a+b]=1;
  }
  
  fs();
  
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++)
      cout<<ans[i][j];
    cout<<endl;
  }
  
  return 0;
}