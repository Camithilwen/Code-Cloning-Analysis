#include <bits/stdc++.h>
using namespace std;
inline int gi(){
  char ch=getchar();int x=0,q=0;
  while(ch<'0' || ch>'9') ch=='-'?q=1:0,ch=getchar();
  while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
  return q?(-x):x;
}
int f[35000][17],w[35000],c[17][17];
void dp(int &x,int y){
  if (x<y) x=y;
  return;
}
int main(){
  int n=gi(),m=gi(),z,a,b,p,S=(1<<n)-1,d=0;
  for (int i=1; i<=m; ++i){
    a=gi(),b=gi(),p=gi();
    c[a][b]+=p,c[b][a]+=p;
    z=(1<<(a-1))|(1<<(b-1));
    for (int s=1; s<(1<<n); ++s)
      if ((s&z)==z)
	w[s]+=p;
    d+=p;
  }
  memset(f,-100,sizeof(f));
  f[1][1]=0;
  for (int s=1; s<=S; ++s)
    for (int i=1; i<=n; ++i)
      if (s&(1<<(i-1))){
	for (int j=1; j<=n; ++j)
	  if (!(s&(1<<(j-1)))&&c[i][j])
	    dp(f[s|(1<<(j-1))][j],f[s][i]+c[i][j]);
	for (int t=S^s; t; t=(t-1)&(S^s))
	  dp(f[s|t][i],f[s][i]+w[t|1<<(i-1)]);
      }
  int ans=0;
  for (int s=1; s<=S; ++s)
    dp(ans,f[s][n]);
  cout<<d-ans;
  return 0;
}
